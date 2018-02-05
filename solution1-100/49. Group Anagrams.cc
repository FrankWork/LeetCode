#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      unordered_map<string, vector<string>> resMap;

      for(int i=0;i<strs.size();i++){
        string key = strs[i];
        sort(key.begin(), key.end());
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