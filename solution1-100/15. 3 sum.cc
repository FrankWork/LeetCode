/*
Given an array S of n integers, are there elements a, b, c in S
such that a + b + c = 0? Find all unique triplets in the array
which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using  namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> vi;
        vector<vector<int>> vvi;
        map<int,int> indexMap;

        sort(nums.begin(),nums.end());
        for(int i=0;i < nums.size();++i){
           indexMap[nums[i]] = i;
//cout <<nums[i]<<",";
        }
//cout <<endl;

        for(int i=0;i<nums.size();++i)
        {
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();++j)
            {
                if(j>i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                int key = -nums[i]-nums[j];
                auto iter = indexMap.find(key);
                if(iter!=indexMap.end() && iter->second>j)
                {
                    vi.clear();
                    vi.push_back(nums[i]);
                    vi.push_back(nums[j]);
                    vi.push_back(key);
                    vvi.push_back(vi);
                }
            }
        }

        return vvi;
    }
};
int main(){
    Solution so;
    vector<int> nums={4,-10,-11,-12,-8,-12,-14,-11,-6,2,-4,2,3,12,-3,-12,-14,-12,-8,-9,-6,-3,10,2,14,10,7,-7,-9,0,-9,10,-2,-5,14,5,-9,7,9,0,-14,12,10,4,9,-8,8,11,-5,-15,-13,-3,-11,4,14,11,-1,-2,-11,5,14,-4,-8,-3,6,-9,9,12,6,3,-10,7,0,-15,-3,-13,-8,12,13,-5,12,-15,7,8,-4,-2,4,2,3,9,-8,2,-10,-1,6,3,-2,0,-7,11,-12,-2,3,-4,-2,7,-2,-3,4,-12,-1,1,10,13,-5,-9,-12,6,8,7,0,7,-6,5,13,8,-14,-12};
    //vector<int> nums={-1,0,1,2,-1,-4};
   // vector<int> nums={0,0,0};
    vector<vector<int>> vvi=so.threeSum(nums);

    for(int i=0;i<vvi.size();i++){
        for(int j=0;j<vvi[i].size();j++)
            cout << vvi[i][j]<<" ";
        cout <<endl;
    }



    return 0;
}
