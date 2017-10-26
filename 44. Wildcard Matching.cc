#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p, int i, int j, vector<vector<int>>& result){
      //backtrace &&  brute force
      if(i==s.size() && j==p.size()){return true;}
      
      if(s[i]==p[j] || p[j]=='?'){
        return isMatch(s, p, i+1,j+1, result);
      }else if(p[j]=='*'){
        for(int k=i;k<=s.size();k++){
          bool res;
          if(result[k][j+1]==-1){
            res = isMatch(s,p,k,j+1, result);
            result[k][j+1] = res?1:0;
          }else{
            res = result[k][j+1]==1?true:false;
          }
          if(res){return true;}
        }
      }
      return false;
    }
    bool isMatch(string s, string p) {
      vector<vector<int>> result(s.size()+1, vector<int>(p.size()+1, -1));
      return isMatch(s, p, 0, 0, result);
    }
};

void print(bool value, bool expect){
  cout << (value?"true":"false") << " " << (expect?"true":"false") << endl;
}
int main(){
  Solution so;
  // print(so.isMatch("aa","a")      , false); 
  // print(so.isMatch("aa","aa")     , true); 
  // print(so.isMatch("aaa","aa")    , false); 
  // print(so.isMatch("aaa","")    , false);   
  // print(so.isMatch("abc","abc")    , true); 
  // print(so.isMatch("aaa","a?a")    , true); 
  // print(so.isMatch("ada","a?a")    , true); 

  // print(so.isMatch("aa", "aa*")    , true); 
  // print(so.isMatch("aa", "*")     , true); 
  // print(so.isMatch("aa", "a*")    , true); 
  // print(so.isMatch("ab", "?*")    , true); 
  // print(so.isMatch("aab", "c*a*b"), false); 
  // print(so.isMatch("abc.out", "*.out"), true); 
  // print(so.isMatch("abc.out", "*.out*"), true); 

  // 10s
  print(so.isMatch("bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab", "b*b*ab**ba*b**b***bba"), false); 
  
  
}