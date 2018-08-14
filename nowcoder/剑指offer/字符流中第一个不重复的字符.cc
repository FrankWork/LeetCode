#include "template.h"

class Solution
{
public:
    vector<int> arr;
    Solution(){
      arr.reserve(256);
    }

  //Insert one char from stringstream
    void Insert(char ch)
    {/*
    第一次出现 1
    重复出现  -1
    没出现    0
    */
         int i = (int)ch;
         if(arr[i]==0){
           arr[i]=1;
         }else if(arr[i]==1){
           arr[i]=-1;
         }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int i=0;
        for(;i<arr.size();++i){
          if(arr[i]==1)return arr[i];
        }
        return '#';
    }

};

int main(){
测试用例:
"google"

对应输出应该为:

"ggg#ll"

}