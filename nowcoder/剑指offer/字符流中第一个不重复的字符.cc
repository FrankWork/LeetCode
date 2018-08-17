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
    vector<int> cnt;
    queue<int> q;
    Solution(){
      for(int i=0;i<256;++i)
          cnt.push_back(0);
    }

  //Insert one char from stringstream
    void Insert(char ch)
    {/*
    第一次出现 1
    重复出现  2,3....
    没出现    0
    */
         int i = (int)ch;
         cnt[i]++;
         if(cnt[i]==1)
          q.push(i);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && cnt[q.front()]>1){
          q.pop();
        }
        if(!q.empty())return (char)q.front();
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