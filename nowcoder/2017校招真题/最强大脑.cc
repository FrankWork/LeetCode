#include <iostream>
#include <vector>
#include <cstdio>
#include<string>
#include <cmath>
#include<algorithm>
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

vector<int> getNext(const string& pat){
  int n=pat.length();
  vector<int> next(n);
  next[0]=0;
  int j=0;
  for(int i=1;i<n;++i){
    while(j>0 && pat[i]!=pat[j]){
      j=next[j-1];
    }
    if(pat[i]==pat[j]){
      ++j;
    }
    next[i]=j;
  }
  return next;
}
int kmp(const string& text, int l, int r, const string& pat){
  int m = text.length(), n = pat.length();

  vector<int> next = getNext(pat);
  // for(int i:next){
  //   cout << i << " "; 
  // }
  // cout << endl;  

  int j=0;
  for(int i=l;i<r;++i){
    // printf("i:%d j:%d\n", i,j);
    while(j> 0 && text[i]!=pat[j]){
      j=next[j-1];
    }

    if(text[i]==pat[j]){
      ++j;
    }
    if(j==n){
      return i-j+1;
    }
  }
  return -1;
}


bool valid(const string& flags, const string& c1, const string&c2){
  bool ans=false;
  int n=flags.length(), n1=c1.length(), n2=c2.length();
    bool forward=false, backward=false;
    int a = kmp(flags, 0, n, c1), b;
    if(a!=-1){
      b=kmp(flags, a+n1, n, c2);
      if(b!=-1){
        ans=true;
      }
    }
    return ans;
}

int main(){
  string flags, c1, c2;
  while(cin>>flags>>c1>>c2){
    bool f=valid(flags, c1, c2);
    reverse(flags.begin(), flags.end());
    bool b=valid(flags, c1, c2);

    if(f&&b)cout<<"both"<<endl;
    else if(f)cout<<"forward"<<endl;
    else if(b)cout<<"backward"<<endl;
    else cout<<"invalid"<<endl;
  }
  
  return 0;
}