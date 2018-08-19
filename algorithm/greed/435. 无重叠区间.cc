#include "template.h"

/**
 * Definition for an interval. */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval&a, Interval&b){
    return a.end<b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& a) {
        /*
         计算最多能组成的不重叠区间个数，然后用区间总个数减去不重叠区间的个数。
            对a的结束时间排序，区间结尾越小，留给后面区间的就越大，
            每次选结尾最小的、并且和前一个不重叠的区间
        */
        if(a.size()<2)return 0;

        sort(a.begin(), a.end(), cmp);
        
        int n=1;// 不重叠个数
        int last=a[0].end;
        for(int i=1;i<a.size();++i){
            if(a[i].start>=last){
                n++;
                last = a[i].end ;
            }
        }
        return a.size()-n;
    }
};

int main(){
    Solution so;
    vector<Interval> a{
        Interval(1,100),Interval(11,22),
        Interval(1,11),Interval(2,12)
    };
    cout << so.eraseOverlapIntervals(a)<<endl;
}