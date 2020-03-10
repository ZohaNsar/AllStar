pthread_cond_t cond0 = PTHREAD_COND_INITIALIZER;

WIRE *wire_create(int signal){
    WIRE *temp = (WIRE *) malloc(sizeof(WIRE));
    temp->signal = signal;
    return temp;
}

NOT *not_create(WIRE *in){
    NOT *temp = (NOT *) malloc(sizeof(NOT));
    temp->in = in;
    temp->out = wire_create(!(temp->in->signal));
    return temp;
}

AND *and_constructor(int num, ...) {
    va_list args;
    va_start(args, num);

    AND *temp = (AND *) malloc (sizeof(AND));

    temp->inputN = num;
    for(int i = 0; i < num; ++i){
        temp->in[i] = wire_create(LOW);
        temp->in[i]->signal = va_arg(args, WIRE *)->signal;
    }
    temp->out = wire_create(LOW);

    and_run(temp);
    return temp;
}

void and_run(AND *gp) {
        gp->out = wire_create(HIGH);
        for(int i = 0; i < gp->inputN; ++i) {
            gp->out->signal = gp->out->signal & gp->in[i]->signal;
        }
}

OR *or_create(int num, ...){
    va_list args;
    va_start(args, num);

    OR *temp = (OR *) malloc (sizeof(OR));

    temp->inputN = num;
    for(int i = 0; i < num; ++i){
        temp->in[i] = wire_create(LOW);
        temp->in[i]->signal = va_arg(args, WIRE *)->signal;
    }
    temp->out = wire_create(LOW);

    or_update(temp);
    return temp;
}

void or_update(OR *gp){
    gp->out = wire_create(HIGH);
    for(int i = 0; i < gp->inputN; ++i) {
        gp->out->signal = gp->out->signal | gp->in[i]->signal;
    }
}

CLOCK *clock_constructor(long int delay){
    CLOCK *cp = (CLOCK *) malloc(sizeof(CLOCK));
    cp->delay = delay;
    cp->condition = cond0 ;
    pthread_create(&(cp->thread_id), NULL, run_clock, cp);
    return cp;
}

void *run_clock(void *args){
    CLOCK *clock = (CLOCK *) args;
    long int delay = clock->delay;

    struct timespec ts = {1, delay};
    while(true){
        nanosleep(&ts, NULL);
        pthread_cond_signal(&(clock->condition));
    }
}

D_FLIPFLOP *df_constructor(CLOCK clock, WIRE *d, WIRE *q, WIRE *qp) {
    D_FLIPFLOP *temp = (D_FLIPFLOP *) malloc(sizeof(D_FLIPFLOP));
    temp->d = wire_create(LOW);
    temp->q = wire_create(LOW);


    return temp;
}

void *run_flipflop(void *args){
    D_FLIPFLOP *df = (D_FLIPFLOP *) args;


}
