#include "template.h"

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        /*  双端队列记录滑动窗口的中的下标
            当前值大于队列尾，从后面弹出
            队列首的位置超过滑动窗口，从前面弹出
            当遍历到滑动窗口大小时，才第一次保存队列首
        */
       vector<int> res;
       deque<int> q;
       for(int i=0;i<num.size();++i){
           while(!q.empty() && num[q.back()]<=num[i])
                q.pop_back();
            while(!q.empty() && i-q.front()+1>size)
                q.pop_front();
            q.push_back(i);
            if(size && i+1>=size)
                res.push_back(num[q.front()]);
       }
       return res;
    }
};

int main(){

}