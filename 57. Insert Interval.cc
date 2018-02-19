#include <vector>
#include <iostream>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      // insert
      bool insert_back=true;
      for(int i=0;i<intervals.size();++i){
        if(intervals[i].start > newInterval.start){
             intervals.insert(intervals.begin()+i, newInterval);
             insert_back=false;
             break;
        }
      }
      if(insert_back){
        intervals.push_back(newInterval);
      }

      // merge (1,5) (2,7)  -> (1,7)
      int current = 0;
      // vector<int> to_erased;
      for(int i=1;i<intervals.size();++i){
        if(intervals[current].end>=intervals[i].start){
          intervals[current].end = max(intervals[current].end, intervals[i].end);
          intervals.erase(intervals.begin()+i);
          --i;
        }else{
          current = i;

        }
      }



      return intervals;
    }
};

int main(){
  Solution so;
  
  // vector<Interval> intervals{
  // };
  // auto res = so.insert(intervals, Interval(2, 5));
  // // [2,5]

  // vector<Interval> intervals{
  //   Interval(1,3), Interval(6,9)
  // };
  // auto res = so.insert(intervals, Interval(2, 5));
  // // [1,5],[6,9]

  vector<Interval> intervals{
    Interval(1,5) 
  };
  auto res = so.insert(intervals, Interval(2, 7));
  // [1,7]

  // vector<Interval> intervals{
  //   Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16)
  // };
  // auto res = so.insert(intervals, Interval(4, 9));
  // // [1,2],[3,10],[12,16]. 


  for(auto i: res){
    cout <<i.start << ", "<<i.end<<endl;
  }

  return 0;
}