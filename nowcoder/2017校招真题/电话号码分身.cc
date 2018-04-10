#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    // if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

template<class T>
void print2d(vector<vector<T>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}


int main(){
  int t;
  cin>>t;
  for(int ii=0;ii<t;++ii){
    string str;
    cin>>str;

    vector<int> nums(10);
    map<char,int> chars;
    for(char c:str){
      ++chars[c];
    }
    int n;
    n = chars['Z'];
    chars['Z']-=n;
    chars['E']-=n;
    chars['R']-=n;
    chars['O']-=n;
    nums[2]+=n;

    n = chars['W'];
    chars['T']-=n;
    chars['W']-=n;
    chars['O']-=n;
    nums[4]+=n;


    n = chars['U'];
    chars['F']-=n;
    chars['O']-=n;
    chars['U']-=n;
    chars['R']-=n;
    nums[6]+=n;


    n = chars['X'];
    chars['S']-=n;
    chars['I']-=n;
    chars['X']-=n;
    nums[8]+=n;


    n = chars['G'];
    chars['E']-=n;
    chars['I']-=n;
    chars['G']-=n;
    chars['H']-=n;
    chars['T']-=n;
    nums[0]+=n;


    n = chars['F'];
    chars['F']-=n;
    chars['I']-=n;
    chars['V']-=n;
    chars['E']-=n;
    nums[7]+=n;


    n = chars['H'];
    chars['T']-=n;
    chars['H']-=n;
    chars['R']-=n;
    chars['E']-=2*n;
    nums[5]+=n;


    n = chars['S'];
    chars['S']-=n;
    chars['E']-=2*n;
    chars['V']-=n;
    chars['N']-=n;
    nums[9]+=n;

    n = chars['O'];
    chars['E']-=n;
    chars['N']-=n;
    chars['O']-=n;
    nums[3]+=n;

    n = chars['I'];
    chars['I']-=n;
    chars['N']-=2*n;
    chars['E']-=n;
    nums[1]+=n;

    for(int i=0;i<nums.size();++i){
      for(int j=0;j<nums[i];++j){
        cout<<i;
      }
    }
    cout<<endl;

  }
  
  return 0;
}