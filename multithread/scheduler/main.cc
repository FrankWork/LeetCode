#include "dispatcher.h"// 调度员
#include "request.h"
#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include <chrono>

using namespace std;

/*
多个request分配给多个worker处理
*/


sig_atomic_t signal_caught = 0;
mutex logMutex;

void sigint_handler(int sig){
    signal_caught = 1;
}

void logFnc(string text){
    logMutex.lock();
    cout <<text <<"\n";
    logMutex.unlock();
}

int main(){
    signal(SIGINT, &sigint_handler);
    // 生成10个worker, 启动10个线程, 等待request
    Dispatcher::init(10);
    cout << "Initialized.\n";

    int cycles = 0;
    Request* rq = 0;
    while(!signal_caught &&cycles<50){// 10个worker, 执行50个请求
        rq = new Request();// 向屏幕输出 启动，结束等信息
        rq->setValue(cycles);
        rq->setOutput(&logFnc);
        Dispatcher::addRequest(rq);
        cycles++;
    }

    this_thread::sleep_for(chrono::seconds(5));
    Dispatcher::stop();// stop workers, join threads

    cout << "clean-up done.\n";
    return 0;
}