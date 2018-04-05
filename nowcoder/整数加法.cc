#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
  string as,bs;
  int n,m;
  while(cin>>as>>bs){
    n=as.length(),m=bs.length();
    vector<int> a(n), b(m);
    bool valid=true;
    for(int i=0;i<n;++i){
      a[i]=as[n-i-1]-'0';
      if(a[i]<0 || a[i]>9){
        valid=false;
        break;
      }
    }
    if(!valid) {
      cout<<"Error"<<endl;
      continue;
    }
    for(int i=0;i<m;++i){
      b[i]=bs[m-i-1]-'0';
      if(b[i]<0 || b[i]>9){
        valid=false;
        break;
      }
    }
    if(!valid) {
      cout<<"Error"<<endl;
      continue;
    }

    vector<int> ans(max(n,m)+1);
    int c=0, t, i;
    for(i=0;i<min(n,m);++i){
      t = a[i]+b[i]+c;
      ans[i]=t%10;
      c=t/10;
    }
    while(i<n){
      t=a[i]+c;
      ans[i++]=t%10;
      c=t/10;
    }
    while(i<m){
      t=b[i]+c;
      ans[i++]=t%10;
      c=t/10;
    }
    if(c!=0){
      ans[i]=c;
    }

    while(ans[i]==0){
      --i;
    }
    while(i>=0){
      cout<<ans[i--];
    }
    cout<<endl;
  }
  
  
  
  return 0;
}