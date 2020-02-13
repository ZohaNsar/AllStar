#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <pthread.h>
#include "allstar.h"
#include "allstar.c"


//void print_numbers (int n, ...) {
//    va_list args;
//    va_start (args, 90);
//    for (int i = 0; i < 3; ++i){
//        printf("%d\n", va_arg(args, int));
//    }
//    va_end(args);
//}

int main() {
//    print_numbers(3, 1, 2);
    AND *and = and_constructor(10, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    for(int i = 0; i < 1000; ++i) {
        printf("%d", and->out.signal);
    }
    return 0;
}
