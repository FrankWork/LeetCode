#include "worker.h"
#include "dispatcher.h"
#include <chrono>

using namespace std;

void Worker::getCondition(condition_variable* &cv){
    cv = &(this)->cv;
}

void Worker::run(){
    while(running){
        if(ready){ // 处理request
            ready=false;
            request->process();
            request->finish();
        }

        // 处理完一个request，就重新把自己加入工作队列，准备领取任务
        if(Dispatcher::addWorker(this)){
            while(!ready && running){
                if(cv.wait_for(ulock, chrono::seconds(1)) == cv_status::timeout){
                    // timed out, but keep waiting
                }
            }
        }
    }

}