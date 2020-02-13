AND *and_constructor(int num, ...){
    va_list args;
    va_start(args, num);

    AND *temp = (AND *) malloc (sizeof(AND));

    temp->inputN = num;
    for(int i = 0; i < num; ++i){
        temp->in[i].signal = va_arg(args, int);
    }
    temp->out.signal = LOW;

    pthread_create(&(temp->thread), NULL, and_run, temp);

    return temp;
}

void *and_run(void *args) {
    AND *gp = (AND *) args;
    while(1) {
        gp->out.signal = HIGH;
        for(int i = 0; i < gp->inputN; ++i) {
            gp->out.signal = gp->out.signal & gp->in[i].signal;
        }
    }
}

