#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    // if(i!=0) cout << " ";
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
string str;

int main(){
  int k=1;
  while(cin>>str>>k){
    // cout <<k<<endl;
    vector<int> nums;
    for(char c:str){
      nums.push_back(c-'0');
    }
    for(int i=0;i<nums.size()-1;++i){
      if(k>0 && nums[i]<nums[i+1]){
        nums.erase(nums.begin()+i);
        --k;
        i=-1;
      }
    }
    while(k){
      nums.pop_back();
      --k;
    }
    
    print(nums);
  }
  return 0;
}