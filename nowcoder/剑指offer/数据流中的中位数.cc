#include "template.h"

class Solution {
    /* 大顶堆保存数据较小的部分    小顶堆保存数据较大的部分
       若堆中元素个数一样， 中位数为 两个堆顶的平均值
       若堆中元素个数相差为1， 且小顶堆元素多，中位数为小顶堆 堆顶
       若   元素个数相差大于1，大顶堆元素插入小顶堆中
    */
private:
    priority_queue<int, vector<int>, greater<int>> small; // 小顶堆
    priority_queue<int, vector<int>, less<int>> big;// 大顶堆
    
public:
    void Insert(int num)
    {
        if(big.empty() || num<=big.top()) big.push(num);
        else small.push(num);

        if(small.size()==big.size()+2) {
          big.push(small.top());
          small.pop();
        }
        if(small.size()+1==big.size()){
          small.push(big.top());
          big.pop();
        }
    }

    double GetMedian()
    { 
      if(big.size()==small.size()) return (big.top()+small.top()) /2.0 ;
      return small.top();
    }

};

int main(){
    priority_queue<int, vector<int>, greater<int>> small;
    for(int i=0;i<10;++i){
      small.push(i);
    }
    cout << small.top();
}