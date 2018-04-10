#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;
 
void print(vector<int> & nums){
  for(int n:nums){
    printf("%2d ", n);
  }
  cout <<endl;
}
 
int main(){
  int n;
  scanf("%d", &n);
  vector<int> nums(n);
  for(int i=0;i<n;++i){
    scanf("%d", &nums[i]);
  }

  
  for(int i=0;i<n;++i){
    // sort(nums.begin(), nums.end());
    for(int j=i+1;j<n;++j){
      if((nums[i]^nums[j])<nums[j]){
        nums[j]=nums[i]^nums[j];
      }
    }
  }

  for(int i: nums){
    bitset<32> bs(i);
    cout << bs << endl;
  }

  int sum=0;
  for(int i=0;i<n;++i){
    if(nums[i]!=0){
      ++sum;
    }
  }
  cout << sum << endl;
  return 0;
}