#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <random>

using namespace std;

/*
mutex
thread
thread_local mt19937 generator
uniform_int_distribution
*/

mutex values_mtx;
mutex cout_mtx;
vector<int> values;

int randGen(const int& min, const int&max){
    static thread_local mt19937 generator(hash<thread::id>()(this_thread::get_id()));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

void threadFnc(int tid){
    cout_mtx.lock();
    cout << "thread "<<tid<<".\n";
    cout_mtx.unlock();

    values_mtx.lock();
    int val = values[0];
    values_mtx.unlock();

    int rval = randGen(0, 10);
    val += rval;

    cout_mtx.lock();
    cout << "thread "<<tid<<" adding "<<rval<<".\n";
    cout_mtx.unlock();

    values_mtx.lock();
    values.push_back(val);
    values_mtx.unlock();

}

int main(){
    values.push_back(42);

    thread tr1(threadFnc, 1);
    thread tr2(threadFnc, 2);
    thread tr3(threadFnc, 3);
    thread tr4(threadFnc, 4);

    tr1.join();
    tr2.join();
    tr3.join();
    tr4.join();
    
    for(int v: values){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}