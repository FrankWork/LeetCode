/*
Given an array S of n integers, are there elements a, b, c, and d in S
such that a + b + c + d = target? Find all unique quadruplets in the array
which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

Tags: Array Hash Table Two Pointers
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vvi;
        if(nums.size()<4) return vvi;

        sort(nums.begin(),nums.end());

        vector<int> vi;
        int left,right,t;

        for(int a=0;a<nums.size();a++){
            if(a>0&&nums[a]==nums[a-1]){
                continue;
            }
            for(int b=a+1;b<nums.size();b++){
                if(b>a+1&&nums[b]==nums[b-1]){
                    continue;
                }

                left=b+1,right=nums.size()-1;
                while(left<right){
                  t=nums[a]+nums[b]+nums[left]+nums[right];
                  if(t<target)left++;
                  else if(t>target)right--;
                  else{
                    vi.clear();
                    vi.push_back(nums[a]);
                    vi.push_back(nums[b]);
                    vi.push_back(nums[left]);
                    vi.push_back(nums[right]);
                    vvi.push_back(vi);
                    do{
                         left++;
                    }while(nums[left-1]==nums[left]);
                    do{
                         right--;
                    }while(nums[right+1]==nums[right]);
                  }

                }
            }
        }

        return vvi;
    }
};

int main(){
    Solution so;
    //vector<int> nums={1 ,0 ,-1 ,0 ,-2, 2};
    //int target=0;
    vector<int> nums={-1,0,-5,-2,-2,-4,0,1,-2};
    int target=-9;
    vector<vector<int>> vvi = so.fourSum(nums,target);
    for(vector<int>& vi: vvi)
    {
        for(int i:vi)
            cout <<i<<",";
        cout <<endl;
    }

    return 0;
}
