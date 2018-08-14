#include "template.h"

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int nums[], int length, int* duplication) {
        for(int i=0;i<length;++i){
          if(nums[i]<0 || nums[i]>=length)return false;
        }

        for(int i=0;i<length;++i){
          if(nums[i]==i){}
          else if(nums[i]!=i){
            int t=nums[i];
            if(t==nums[t]){
              *duplication=t;
              return true;
            }else{
              nums[i]=nums[t];
              nums[t]=t;
              i--;
            }
          }
        }
        return false;
    }
};

int main(){
int nums[]={2,3,1,0,2,5,3};
Solution so;
int t;
so.duplicate(nums, 7, &t);
cout <<t<<endl;
}