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
int partition(vector<int>&nums, int low, int high){
  int x=nums[high];
  int l=low-1, r=low;
  while(r<high){
    if(nums[r]<nums[high]){
      ++l;
      swap(nums[l], nums[r]);
    }
    ++r;
  }
  ++l;
  swap(nums[l], nums[high]);
  return l;
}
void qsort(vector<int>&nums, int low, int high){
  if(low<high){
    int p = partition(nums, low, high);
    qsort(nums, low, p-1);
    qsort(nums, p+1, high);
  }
}
int main(){
  vector<int> nums{10, 9,8,7,6,5,0};
  qsort(nums, 0, nums.size()-1);
  print(nums);
  
  return 0;
}