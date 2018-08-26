#include "../template.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        /* ip分四段，每段含有1-3个字符， 每段的值小于255
        */
       vector<string> res;
       backtrack(res, s, "", 0);
       return res;
    }
    void backtrack(vector<string>&res, string s, string tmp, int idx){
      // idx: ip第idx段，
      // cout<<tmp<<" "<<s<<" "<<idx<<endl;

      if(idx==4 && s.length()==0) {res.push_back(tmp); return;}
      if(idx==4 || s.length()==0) return ;
      // if(s[0]=='0')return;

      // cout<<tmp<<" "<<s<<endl;
      for(int i=1;i<=s.length() && i<4; ++i){
          string part = s.substr(0, i);
            

          if(stoi(part)<=255){
            if(tmp.length()!=0) part = "." + part;

            // cout<<tmp<<" "<<part<<" "<<s<<" "<<s.substr(i-1)<<endl;
            

            backtrack(res, s.substr(i), tmp+part, idx+1);
          }
      }
    }
};

int main(){
    Solution so;
    // vector<string> res = so.restoreIpAddresses("25525511135");
    // print(res);

    vector<string> res = so.restoreIpAddresses("0000");
    print(res);//0.0.0.0

    // string str="abcdefg";
    // cout << str.substr(2)<<endl;// cdefg
}