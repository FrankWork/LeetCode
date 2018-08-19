#include "template.h"

class Solution {
public:
    string frequencySort(string s) {
        /*桶排序， 按频数划分桶， 从后往前输出
        */
       unordered_map<char, int> freq;
       for(auto c:s){
         freq[c]++;
       }
       vector<vector<char>> buck(s.length(), vector<char>());
       for(auto it=freq.begin();it!=freq.end();++it){
          buck[it->second-1].push_back(it->first);
          printf("%c %d\n", it->first, it->second);
       }
       string res;
       for(int i=buck.size()-1;i>=0;--i){   // 遍历桶（频数）
         for(int j=0;j<buck[i].size();++j){ // 遍历字符
           for(int k=0;k<i+1;++k)
              res += buck[i][j];
         }
       }
       return res;
    }
};

int main(){
  Solution so;
  cout << so.frequencySort("tree")<<endl;
}