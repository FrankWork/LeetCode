#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void bt(string &str, vector<string>& res, int idx){
      if(idx==str.length()-1){
        res.push_back(str);
        return;
      }
      for(int i=idx;i<str.length();++i){
        if(i>idx && str[i]==str[idx]){
          continue;
        }
        swap(str[i], str[idx]);
        // cout <<i<<" "<<str<<endl;
        bt(str, res, idx+1);
        swap(str[i], str[idx]);
      }
    }
    vector<string> Permutation(string &str) {
        vector<string> res;
        // sort(str.begin(), str.end());
        bt(str, res, 0);
        sort(res.begin(), res.end());
        return res;
    }
};

int main(){
  Solution so;
  string str="abc";
  // str="aa";
  // str="aab";
  str="aabc";
  vector<string> vec = so.Permutation(str);
  for(auto &s:vec){
    cout<<s<<endl;
  }
}