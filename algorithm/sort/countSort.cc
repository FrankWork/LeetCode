#include "template.h"

void countSort(vector<int>& nums){
    int n=nums.size();
    vector<int> cnt(n);

    for(int i=0;i<n;++i){
        int t=nums[i];
        cnt[t]++;
    }
    
    int idx=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<cnt[i];++j){
            nums[idx++] = i;
        }
    }
    return ;
}

int main(){
    vector<int> nums{2,1,3,4,2,5,6,1,8,11};
    countSort(nums);
    print(nums);
}