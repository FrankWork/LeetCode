#include "dispatcher.h"
#include <iostream>
using namespace std;

queue<AbstractRequest*> Dispatcher::requests;
queue<Worker*> Dispatcher::workers;    // worker队列，准备处理request
mutex Dispatcher::requestsMutex;
mutex Dispatcher::workersMutex;
vector<Worker*> Dispatcher::allWorkers;// 存放所有生成的worker
vector<thread*> Dispatcher::threads;

bool Dispatcher::init(int workers){
    thread* t=0;
    Worker* w=0;
    for(int i=0;i<workers;++i){
        w = new Worker;
        allWorkers.push_back(w);
        t = new thread(&Worker::run, w);
        threads.push_back(t);
    }
    return true;
}

bool Dispatcher::stop(){
    for(int i=0;i<allWorkers.size();++i){
        allWorkers[i]->stop();
    }
    cout << "stopped workers.\n";
    for(int j=0;j<threads.size();++j){
        threads[j]->join();
        cout << "joined threads.\n";
    }
    return true;
}

void Dispatcher::addRequest(AbstractRequest* request){
    workersMutex.lock();
    if(!workers.empty()){
        // 选择一个worker来处理request
        Worker* worker = workers.front();
        worker->setRequest(request);        
        condition_variable* cv;
        worker->getCondition(cv);
        cv->notify_one();// 通知自己该工作了
        workers.pop();
        workersMutex.unlock();
    }else{  // 工作者队列为空，将请求加入任务队列缓存
        workersMutex.unlock();
        requestsMutex.lock();
        requests.push(request);
        requestsMutex.unlock();
    }
}

bool Dispatcher::addWorker(Worker* worker){
    // 将worker加入工作队列，准备领取任务
    bool wait = true;
    requestsMutex.lock();
    if(!requests.empty()){
        // 从任务队列中领取一个任务，不需要等待，直接工作
        AbstractRequest* request = requests.front();
        worker->setRequest(request);
        requests.pop();
        wait=false;
        requestsMutex.unlock();
    }else{
        requestsMutex.unlock();
        // 将worker加入工作队列，等待任务
        workersMutex.lock();
        workers.push(worker);
        workersMutex.unlock();
    }
    return wait;
}