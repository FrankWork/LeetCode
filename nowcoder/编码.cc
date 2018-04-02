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

  int ans=0, level=0;
  vector<char> chars(25);
  for(int i=0;i<25;++i){
    chars[i]=(char)i+'a';
  }

  // cout << ans << endl;

  for(int j=0;j<code.size();++j){
    for(int i=0;i<chars.size();++i){
      if(chars[i]!=code[j]){
        ans+=pow(25, 3-j);
      }else{
        ++ans;
        printf("%d %c\n", ans, chars[i]);
        break;
      }
    }
  }

  cout << ans <<endl;

  return 0;
}