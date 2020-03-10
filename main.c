#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <pthread.h>
#include "allstar.h"
#include "allstar.c"

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//void print_numbers (int n, ...) {
//    va_list args;
//    va_start (args, 90);
//    for (int i = 0; i < 3; ++i){
//        printf("%d\n", va_arg(args, int));
//    }
//    va_end(args);
//}

int main() {
//    CLOCK *clock = clock_constructor(500000000L);
//    puts("hi3");
//    pthread_mutex_lock(&lock);
//    puts("hi4");
//    printf("main :%p\n", &(clock->condition));
//    pthread_cond_wait(&(clock->condition), &lock);
//    puts("hihi");
//    pthread_mutex_unlock(&lock);
//    puts("hi");
    WIRE *a = wire_create(HIGH);
    WIRE *b = wire_create(HIGH);
    WIRE *c = wire_create(HIGH);
    WIRE *d = wire_create(HIGH);
    WIRE *e = wire_create(HIGH);

    AND *and0 = and_constructor(3, a, b, c);
    d = and0->out;
    AND *and1 = and_constructor(2, d,e);
    printf("%d\n", and0->out->signal);
    return 0;
}
