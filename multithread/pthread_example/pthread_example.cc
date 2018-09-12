#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_THREADS 5

/*
pthread_t
pthread_mutex_t

pthread_mutex_lock
pthread_mutex_unlock

pthread_create
pthread_join
*/
static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;

void func(int id){
    pthread_mutex_lock(&func_mutex);
    
    // do something
    printf("%d\n", id);

    pthread_mutex_unlock(&func_mutex);
}

void* worker(void* args){
    int value = *((int*)args);
    func(value);

    return 0;   
}

int main(int argc, char** argv){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;
    printf("hello");

    for(unsigned int i=0;i<NUM_THREADS;++i){
        thread_args[i]=i;
        result_code = pthread_create(&threads[i],0,worker, (void*) & thread_args[i]);
    }
    for(int i=0;i<NUM_THREADS;++i){
        result_code = pthread_join(threads[i], 0);
    }
    exit(0);
}