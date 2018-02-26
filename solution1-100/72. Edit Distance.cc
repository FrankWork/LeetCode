#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


void print(vector<vector<int>> &path){
    for(auto vec: path){
        for(int i: vec){
            cout << i << " ";
        }
        cout << '\n';
    }
}

int min(int a, int b, int c){
  return min(min(a, b), c);
}

class Solution {
public:
    
    int minDistance(string word1, string word2) {
      int m=word1.length(), n=word2.length();
      if(m==0||n==0){
        return max(m,n);
      }
      vector<vector<int>> distance(m+1, vector<int>(n+1, 0));
      for(int i=0;i<=m;++i){
        distance[i][0]=i;
      }
      for(int j=0;j<=n;++j){
        distance[0][j]=j;
      }
      
      for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
          int d = min(distance[i-1][j-1], distance[i-1][j], distance[i][j-1]);
          if(word1[i-1] != word2[j-1]){
            distance[i][j] = d+1;
          }else{
            distance[i][j] = distance[i-1][j-1];
          }
        }
      }
      // print(distance);

      return distance[m][n]; 
    }
};

int main(){
  Solution so;
  cout << so.minDistance("", "a") << endl;      // 1
  cout << so.minDistance("b", "") << endl;      // 1
  cout << so.minDistance("a", "a") << endl;     // 0
  cout << so.minDistance("a", "b") << endl;     // 1
  cout << so.minDistance("sea", "eat") << endl; // 2
  cout << so.minDistance("ab", "bc") << endl;   // 2
  // cout << so.minDistance("zoologicoarchaeologist", "zoogeologist") << endl; // 10
  //  cout << so.minDistance("oogoeo", "ogeo") << endl; // 2
  //  cout << so.minDistance("oo", "o") << endl; // 1
}