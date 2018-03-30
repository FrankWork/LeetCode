#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

void print2d(vector<vector<int>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}


int main(){
  
  int m,n;
  cin>>m>>n;
  bool pos=m>0;
  if(!pos)m=-m;
  vector<int> nums;
  while(m){
    nums.push_back(m%n);
    m/=n;
  }
  // print(nums);
  if(!pos){
    cout<<'-';
  }
  for(int i=nums.size()-1;i>=0;--i)
  {
    if(nums[i]<10)
      cout <<nums[i];
    else
      cout <<(char)(nums[i]-10+'A');
  }
  cout<<endl;

  return 0;
}