#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

int main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;++i)
    cin>>nums[i];
  int l=0, r=n-1,sum=0;
  while(l<=r){
    if(nums[l]<nums[r]){
      nums[l+1]+=nums[l];
      ++l;++sum;
    }else if(nums[l]>nums[r]){
      nums[r-1]+=nums[r];
      --r;++sum;
    }else{
      ++l;--r;
    }
  }
  // print(nums);
  cout <<sum<<endl;
}