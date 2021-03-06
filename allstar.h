#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUSIZE 32
#define HIGH 1
#define LOW 0


typedef struct {
    unsigned char signal : 1;
} WIRE;

typedef struct {
    WIRE *in;
    WIRE *out;
} NOT;

typedef struct {
    int inputN;
    WIRE *in[BUSIZE];
    WIRE *out;
} AND;

typedef struct {
    int inputN;
    WIRE *in[BUSIZE];
    WIRE *out;
} OR;

typedef struct {
    long int delay;
    pthread_t thread_id;
    pthread_cond_t condition;
} CLOCK;

typedef struct {
  CLOCK clock;
  WIRE *d;
  WIRE *q;
  WIRE *qp;
} D_FLIPFLOP;

//functions
WIRE *wire_create(int signal);

NOT *not_create(WIRE *in);

AND *and_constructor(int num, ...);
void and_run(AND *gp);

OR *or_create(int num, ...);
void or_update(OR *gp);

CLOCK *clock_constructor(long int delay);
void *run_clock(void *args);

D_FLIPFLOP *df_constructor(CLOCK clock, WIRE *d, WIRE *q, WIRE *qp);
void *df_run(void *args);
