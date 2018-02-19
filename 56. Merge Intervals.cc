#include <vector>
#include <iostream>
#include <algorithm>    // std::sort

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool cmp(Interval i, Interval j){
  return i.start < j.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        vector<Interval> res;
        Interval temp(-1, -1);
        int i=0;

        while(i<intervals.size()){
          if(temp.start==-1){
            temp.start = intervals[i].start;
            temp.end = intervals[i].end;
            ++i; continue;
          }
          if(temp.end>=intervals[i].start){
            temp.end=max(intervals[i].end, temp.end);
            ++i; continue;
          }else{
            res.push_back(temp);
            temp.start=intervals[i].start;
            temp.end = intervals[i].end;
          }

        }
        if(temp.start!=-1){
          res.push_back(temp);
        }
        return res;
    }
};

int main(){
  Solution so;
  vector<Interval> intervals{
    // Interval(1,3), Interval(2,6), Interval(8,10),Interval(15,18)
    // Interval(1,4), Interval(4,5)
    // Interval(1,4), Interval(0, 4)
    Interval(1,4), Interval(2, 3)
  };
  auto res = so.merge(intervals);
  for(auto i: res){
    cout <<i.start << ", "<<i.end<<endl;
  }

  return 0;
}