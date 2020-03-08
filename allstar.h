#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
;;;;;;;;;;;;;;;;;;;
#define BUSIZE 32
#define HIGH 1
#define LOW 0
//#define Wire wire
;;;;;;;;;;;;;;;;;;;;

typedef struct {
    unsigned char signal : 1;
} Wire;

typedef struct {
    Wire *in;
    Wire *out;
} NOT;

typedef struct {
    int inputN;
    Wire *in[BUSIZE];
    Wire *out;
} AND;

typedef struct {
    int inputN;
    Wire *in[BUSIZE];
    Wire *out;
} OR;

typedef struct {
    long int delay;
    pthread_t thread_id;
    pthread_cond_t condition;
} CLOCK; 

typedef struct {
  CLOCK clock;
  Wire *d;
  Wire *q;
  Wire *qp;
} D_FLIPFLOP;

//functions
Wire *wire_create(int signal);

NOT *not_create(Wire *in);

AND *and_constructor(int num, ...);
void and_run(AND *args);

OR *or_create(int num, ...);
void or_run(OR *args);

CLOCK *clock_constructor(long int delay);
void *run_clock(void *args);

D_FLIPFLOP *df_constructor(CLOCK clock, Wire *d, Wire *q, Wire *qp);
void *df_run(void *args);

