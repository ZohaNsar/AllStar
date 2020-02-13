#include <stdarg.h>

#define BUSIZE 32
#define HIGH 1
#define LOW 0

typedef struct{
    unsigned char signal : 1;
}Wire ;

typedef struct{
    int inputN;
    pthread_t thread;
    Wire in[BUSIZE];
    Wire out;
}AND;


//functions
AND *and_constructor(int num, ...);
void and_run(AND *args);