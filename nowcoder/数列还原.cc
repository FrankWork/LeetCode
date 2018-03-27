#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> & nums){
  for(int n:nums){
    cout << n << " ";

  }
  cout <<endl;
}

void getPerm(int idx, int n, vector<int>& nums, vector<vector<int>>&perms){
  if(idx==n){
    perms.push_back(nums);
    // print(nums);
    return ;
  }

  for(int i=idx;i<n;++i){
    swap(nums[i], nums[idx]);

    getPerm(idx+1, n, nums, perms);
    swap(nums[i], nums[idx]);
  }

}

int main(){
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> A(n);
    for(int i=0;i<n;++i){
        cin >> A[i];
    }

    vector<int> nums;
    for(int i=1;i<=n;++i){
      bool find=false;
      for(int j=0;j<n;++j){
        if(i==A[j]){
          find=true;
        }
      }
      if(!find){
        nums.push_back(i);
      }
    }

    vector<vector<int>> partPerms;
    getPerm(0, nums.size(), nums, partPerms);


    vector<vector<int>> perms;
    
    for(int idx=0;idx<partPerms.size();++idx){
      perms.push_back(A);

      int j=0;
      for(int i=0;i<A.size();++i){
        if(perms[idx][i]==0){
          perms[idx][i] = partPerms[idx][j++];
        }
      }
      // print(perms[idx]);
    }

    vector<int> validK(perms.size(), 0);

    for(int idx=0;idx<perms.size();++idx){
      for(int i=1;i<n;++i){
        for(int j=0;j<i;j++){
          if(perms[idx][j]<perms[idx][i]){
            ++validK[idx];
          }
        }
      }
    }
    int sum=0;
    for(int i=0;i<validK.size();++i){
      if(validK[i]==k){
        ++sum;
      }
    }
    cout << sum;
}