#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
      int m=word1.length(), n=word2.length();
      int i=0, distance=0;
      for(;i<m && i<n;++i){
        if(word1[i] != word2[i]){
          ++distance;
        }
      }
      distance += max(m,n)-min(m,n);
      
      return distance;
    }
};

int main(){
  Solution so;
  cout << so.minDistance("", "a") << endl;      // 1
  cout << so.minDistance("a", "a") << endl;     // 0
  cout << so.minDistance("sea", "eat") << endl; // 2

}