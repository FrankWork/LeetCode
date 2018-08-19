#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int nums[], int length, int* duplication) {
        /* 将i位置存放数i
        */
        for(int i=0;i<length;++i){
            t=nums[i];
            if(t<0 || t>=length)return false;

            if(t!=i ){
                if(t==nums[t]){*duplication=t;return true;}
                swap(nums[i], nums[t]);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    // vecotr<int> nums
    Solution so;

    int nums[]={2,3,1,0,2,5,3};
    int t=-1;
    so.duplicate(nums, 7, &t);
    cout << t<<endl;
    return 0;
}
