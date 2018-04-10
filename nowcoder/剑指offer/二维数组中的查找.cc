#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

template<class T>
void print2d(vector<vector<T>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}

class Solution {
public:
    bool Find(int target, vector<vector<int> >& array) {
        if(array.empty() || array[0].empty())
          return false;

        int n=array.size(), m=array[0].size();
        int r=n-1,c=0;
        while(r>=0&&c<m){
          if(array[r][c]==target){
            return true;
          }else if(array[r][c]<target){
            ++c;
          }else{
            --r;
          }
        }
        
        return false;
    }
};

int main(){
  vector<vector<int>> matrix{
    {1,2,8,9},
    {2,4,9,12},
    {4,7,10,13},
    {6,8,11,15}
  };

  Solution so;
  cout <<so.Find(7, matrix)<<endl;
  cout <<so.Find(1, matrix)<<endl;
  
  return 0;
}