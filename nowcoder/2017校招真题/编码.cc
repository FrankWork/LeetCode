#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include<map>
#include <string>
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
  string code;
  cin>>code;
  int n=25, depth=4;
  // int n=3, depth=3;

  int ans=0;
  vector<char> chars(n);
  for(int i=0;i<n;++i){
    chars[i]=(char)i+'a';
  }

  for(int j=0;j<code.size();++j){
    for(int i=0;i<chars.size();++i){
      if(chars[i]!=code[j]){
        for(int k=0;k<=depth-j-1;++k){
          ans+=pow(n,k);
        }
        // printf("!= %d %c\n", ans, chars[i]);
      }else{
        ++ans;
        // printf("== %d %c\n", ans, chars[i]);
        break;
      }
    }
  }
  cout << ans-1 << endl;

  return 0;
}