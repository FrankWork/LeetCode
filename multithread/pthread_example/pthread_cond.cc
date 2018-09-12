#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define COUNT_TRIGGER 10
#define COUNT_LIMIT 12

/*
    pthread_attr_t
    pthread_attr_init
    pthread_attr_setdetachstate
    pthread_attr_destroy

    pthread_mutex_t
    pthread_mutex_init
    pthread_mutex_lock
    pthread_mutex_unlock
    pthread_mutex_destroy

    pthread_cond_t
    pthread_cond_signal
    pthread_cond_wait
    pthread_cond_destroy

    pthread_t
    pthread_create
    pthread_join
    pthread_exit
*/

int count = 0;
int thread_ids[3]={0,1,2};

pthread_mutex_t count_mtx;
pthread_cond_t  count_cv;

void* add_count(void* t){
    int tid=(long)t;
    for(int i=0;i<COUNT_TRIGGER;++i){
        pthread_mutex_lock(&count_mtx);
        count++;
        if(count==COUNT_LIMIT){
            printf("tid %d: send signal to watcher\n", tid);
            pthread_cond_signal(&count_cv);
        }

        pthread_mutex_unlock(&count_mtx);
        sleep(1);
    }
    pthread_exit(0);
}

void* watch_count(void* t){
    int tid=(long) t;

    pthread_mutex_lock(&count_mtx);
    if(count < COUNT_LIMIT){
        pthread_cond_wait(&count_cv, &count_mtx);
    }
    
    printf("tid %d: receive signal, count reach limit.\n", tid);

    pthread_mutex_unlock(&count_mtx);
    pthread_exit(0);
}

int main(int argc, char* argv[]){
    int tid1=1, tid2=2, tid3=3;
    pthread_t threads[3];
    pthread_attr_t attr;

    pthread_mutex_init(&count_mtx, 0);
    pthread_cond_init(&count_cv, 0);

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    pthread_create(&threads[0], &attr, watch_count, (void*) tid1);
    pthread_create(&threads[1], &attr, add_count, (void*) tid2);
    pthread_create(&threads[2], &attr, add_count, (void*) tid3);
    
    for(int i=0;i<3;++i){
        pthread_join(threads[i], 0);
    }

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&count_mtx);
    pthread_cond_destroy(&count_cv);

    return 0;
}