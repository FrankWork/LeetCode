/*
Given an array S of n integers, find three integers in S
such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input
would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int left,right;
        int sum=nums[0]+nums[1]+nums[2], diff=abs(target-sum);
        bool foundt=false;

        sort(nums.begin(),nums.end());
for(int i=0;i<nums.size();i++)
        cout <<nums[i]<<",";
cout <<endl;

        for(int i=0;i<nums.size() && !foundt;i++){
            left=0,right=nums.size()-1;
            while(left<right){
                if(left==i){
                    left++;
                    continue;
                }else if(right==i){
                    right--;
                    continue;
                }

                int t = nums[left]+nums[right]+nums[i];
                int d = abs(target-t);

                if(t>target){
                    right--;
                }else if(t<target){
                    left++;
                }else{ foundt=true;sum=t;break;}

                if(d<diff){
                    diff=d;
                    sum=t;
                }
            }

        }
        return sum;
    }
private:
    int abs(int x){return x>=0?x:-x;}
};
int main(){
    Solution so;
    //vector<int> nums={-1,2,1,-4};
    //int target=1;
    vector<int> nums={1,1,-1,-1,3};
    int target=-1;
    cout <<so.threeSumClosest(nums,target)<<endl;
    return 0;
}
