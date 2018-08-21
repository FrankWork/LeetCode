#include "template.h"

class Solution {
public:
    vector<int> partitionLabels(string &s) {
      /* 记录每个字符最后出现的位置
         b, e记录区间的开始和结尾
         e为b,e之间字符最后出现位置的最大值
      */
      int c;
      vector<int> index(26);
      for(int i=0;i<s.length();++i){
        c = s[i]-'a';
        index[c] = i;
      }
      // print(index);

      vector<int> res;
      int b=0,e=0;
      while(b<s.length()){
        e = b;
        for(int i=b;i<=e;++i){
          c = s[i]-'a';
          e=max(e, index[c]);
        }
        // printf("%d %d\n", b, e);
        res.push_back(e-b+1);
        b=e+1;
        
      }
      return res;
    }
};

int main(){
  Solution so;
  string s="ababcbacadefegdehijhklij";
  vector<int> res=so.partitionLabels(s);
  print(res);
}