#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

struct Custom{
  int num;
  int gain;
  Custom(){this->num=0;this->gain=0;}
  Custom(int num, int gain):num(num),gain(gain){}
  bool operator<(Custom& other){
    return this->gain>other.gain;
  }
};

bool fit(int n, vector<int>& desk){
  int l=0,r=desk.size()-1,m;
  while(l<=r){
    m=(l+r)/2;
    if(desk[m]==n){
      desk.erase(desk.begin()+m);
      return true;
    }else if(desk[m]<n){
        l=m+1;
    }else if(desk[m]>n){
        r=m-1;
    }
  }
  if(l<desk.size()){
      desk.erase(desk.begin()+l);
      return true;
  }
  return false;
}

int main(){
  int n,m;
  long long ans=0;
  cin >>n>>m;
  vector<int> desk(n);
  for(int i=0;i<n;++i){
    cin>>desk[i];
  }
  // print(a);
  sort(desk.begin(), desk.end());

  vector<Custom> custom(m);
  for(int i=0;i<m;++i){
    cin>>custom[i].num>>custom[i].gain;
  }
  sort(custom.begin(), custom.end());
  // for(int i=0;i<m;++i){
  //   printf("%d %d\n", custom[i].num, custom[i].gain);
  // }

  for(int i=0;i<m;++i){
    if(fit(custom[i].num, desk)){
      ans += custom[i].gain;
    }
  }
  // vector<int> num(m),gain(m);
  // for(int i=0;i<m;++i){
  //   cin>>num[i]>>gain[i];
  // }
  // sort(gain.begin(), gain.end());

  
  // print(b);
  // print(c);
  cout << ans <<endl;
  return 0;
}