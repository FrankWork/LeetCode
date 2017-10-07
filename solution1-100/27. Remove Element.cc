/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Hide Tags Array Two Pointers
Hide Similar Problems (E) Remove Linked List Elements

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int index = 0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=val)
        {
            nums[index++]=nums[i];
        }

        return index;
    }
};

void print(vector<int>&nums, int sz){
    for(int i=0;i<sz;i++)
        cout <<nums[i]<<",";
    cout <<endl;
}
int main(){
    Solution so;
    vector<int> vi={1,1,2,2,3,3};
    int sz = so.removeElement(vi, 2);
    cout <<sz<<endl;
    print(vi,sz);
    return 0;
}
