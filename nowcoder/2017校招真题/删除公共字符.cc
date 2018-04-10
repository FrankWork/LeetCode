#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <unordered_set>
using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

void print2d(vector<vector<int>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}


int main(){
  string a,b;
  getline(cin, a);
  getline(cin, b);

  unordered_set<char> chars;
  for(char c:b){
    chars.insert(c);
  }
  // for(char c:chars)
  //   cout << c << endl;
  for(int i=0;i<a.size();++i){
    if(chars.find(a[i])!=chars.end()){
      a.erase(a.begin()+i);
      --i;
    }
  }
  cout << a << endl;
  return 0;
}