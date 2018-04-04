#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include<algorithm>
#include<bitset>
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

struct TrieTree{
  int count;
  struct TrieTree* next[2]{NULL, NULL};
  TrieTree():count(1){}
};

long query(TrieTree* tree, int a, int m, int idx){
  if(NULL==tree)return 0;
  TrieTree* cur=tree;
  for(int i=idx;i>=0;--i){
    int aBit = (a>>i)&1;
    int mBit = (m>>i)&1;
    if(1==aBit && 1==mBit){
      if(NULL==cur->next[0])
        return 0;
      cur=cur->next[0];
    }else if(0==aBit && 1==mBit){
      if(NULL==cur->next[1])
        return 0;
      cur=cur->next[1];
    }else if(1==aBit && 0==mBit){
      long val0 =  (NULL == cur->next[0]) ? 0 : cur->next[0]->count;
      long val1 =  query(cur->next[1],a,m,i-1);
      return val0+val1;
    }else if(0 == aBit && 0 == mBit)
    {
      long val0 =  query(cur->next[0],a,m,i-1);
      long val1 =  (NULL == cur->next[1]) ? 0 : cur->next[1]->count;
      return val0+val1;
    }
  }
  return 0;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  for(int i=0;i<n;++i){
    cin>>nums[i];
  }
  
  TrieTree* tree=new TrieTree();
  for(int i=0;i<n;++i){
    TrieTree* cur=tree;
    for(int j=16;j>=0;--j){
      int t=(nums[i]>>j)&1;
      if(NULL==cur->next[t]){
        cur->next[t]=new TrieTree();
      }else{
        ++(cur->next[t]->count);
      }
      cur=cur->next[t];
    }
  }  
  long ans=0;
  for(int i=0;i<n;++i){
    ans+= query(tree, nums[i], m, 16);
  }
  printf("%ld\n", ans/2);
  
  return 0;
}