#include "template.h"


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
void printIntervals(vector<Interval> &vec){
    for(int i=0;i<vec.size();++i){
        printf("[%d, %d] ", vec[i].start, vec[i].end);
    }
    cout <<endl;
}

bool cmp(Interval&a, Interval&b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &vec) {
        /* 按区间起始位置进行排序
        last 记录前一个点的end，
            如果当前节点start大于last，当前节点不重叠，不用合并
                            小于    ，当前节点重叠，last= max(last, 当前节点的end)
        */
        vector<Interval> res;
        if (vec.empty()) return res;
        sort(vec.begin(), vec.end(), cmp);
        res.push_back(vec[0]);

        int last=vec[0].end, idx=0;
        for(int i=1;i<vec.size();++i){
            if(vec[i].start > last){
                res[idx++].end = last;
                last = vec[i].end;
                res.push_back(vec[i]);
            }else{
                last = max(last, vec[i].end);
            }
        }
        if(last>res[idx].end){//更新最后一个
            res[idx].end=last;
        }
        return res;
    }
};

int main(){
    vector<Interval> nums{Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
    // return[1,6],[8,10],[15,18].
    Solution so;
    vector<Interval> res = so.merge(nums);
    printIntervals(res);

    // [[2,3],[4,5],[6,7],[8,9],[1,10]] -> [1,10]
}