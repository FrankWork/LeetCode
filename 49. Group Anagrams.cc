#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> res;
      
      return res;
    }
};

int main(){
  Solution so;

  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  so.groupAnagrams(strs);
  // ["ate", "eat","tea"],
  // ["nat","tan"],
  // ["bat"]
}