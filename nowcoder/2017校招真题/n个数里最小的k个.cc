#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& nums, int l, int r){
  int small=l-1, large=l;
  while(large<r){
    if(nums[large]<nums[r]){
      ++small;
      swap(nums[small], nums[large]);
    }
    ++large;
  }
  ++small;
  swap(nums[small], nums[r]);
  return small;
}

void sortK(vector<int>& nums, int l, int r, int k){
  if( l<r){
    int p = partition(nums, l, r);
    int n = p-l+1;
    if(n<k) sortK(nums, p+1, r, k-n);
    else   sortK(nums, l, p-1, k);
    // if(p>k-1)
    // if(p<k-1)sortK(nums, p+1, r, k);
  }
}

int main(){
    vector<int> nums;//{3, 9, 6, 8, -10, 7, -11, 19, 30, 12, 23, 5};
    int n;
    while(cin >> n){
        nums.push_back(n);
    }
    int k = nums.back();
    nums.pop_back();
    sortK(nums, 0, nums.size()-1, k);
    sort(nums.begin(), nums.begin()+k);
    for(int i=0;i<k;++i){
        if(i!=0){
            cout << " ";
        }
      cout << nums[i];
    }
    return 0;
}