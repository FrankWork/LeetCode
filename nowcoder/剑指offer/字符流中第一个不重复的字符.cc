#include "template.h"

void print(vector<int> &arr){
  for(int i=0;i<arr.size();++i){
    cout << arr[i]<<" ";
  }
  cout <<endl;
}
class Solution
{
public:
    vector<int> arr;
    Solution(){
      for(int i=0;i<256;++i)
          arr.push_back(0);
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
        // print(arr);
        for(;i<arr.size();++i){
          if(arr[i]==1)return (char)i;
        }
        return '#';
    }

};

int main(){
    Solution so;
    string str="google";
    for(int i=0;i<str.length();++i){
      so.Insert(str[i]);
      cout <<so.FirstAppearingOnce();
    }

// "ggg#ll"

}