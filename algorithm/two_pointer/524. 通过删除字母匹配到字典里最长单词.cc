#include "template.h"

class Solution {
public:
    string findLongestWord(string &s, vector<string>& d) {
          /*
            对字典中每个字符串都匹配一下
            匹配方法使用双指针，
              i, s字符串下标
              j，d中字符串下标
          */
         string best;
         for(string& t:d){
           if(match(s, t)){
            //  update best;
            int n=best.length(), m=t.length();
            if(n<m) best=t;
            else if(n==m && best>t) best=t;
           }
         }
         return best;
    }
    bool match(string& s, string& t){
      /*  遍历s, 若当前字符相等， t前移
          若结果匹配，则j走到t末尾位置
      */
      int i=0,j=0;
      int n=s.length(), m=t.length();
      for(int i=0;i<n;++i){
        if(s[i]==t[j]) ++j;
      }
      return j==m;
    }
};

int main(){
  Solution so;
  string s="abpcplea";
  vector<string> d={"ale","apple","monkey","plea"};
  cout << so.findLongestWord(s, d)<<endl;
}