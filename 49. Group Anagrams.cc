#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      map<string, vector<string>> resMap;

      for(int i=0;i<strs.size();i++){
        string key = strs[i];
        sort(key.begin(), key.end());
        auto it = resMap.find(key);
        if(it==resMap.end()){
          vector<string> buf;
          resMap[key]=buf;
        }
        resMap[key].push_back(strs[i]);
      }

      for(auto it=resMap.begin(); it!=resMap.end();++it){
        res.push_back(it->second);
      } 
      return res;
    }
};

void print(vector<string>& strs){
  for(int i=0;i<strs.size();i++){
    cout << strs[i]<<"\t";
  }
  cout << endl;
}


void print2d(vector<vector<string>> res){
  for(int i=0;i<res.size();i++){
    print(res[i]);
  }
  cout << endl;
}
int main(){
  Solution so;

  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  print2d(so.groupAnagrams(strs));
  // ["ate", "eat","tea"],
  // ["nat","tan"],
  // ["bat"]
  
}