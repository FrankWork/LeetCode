#include<iostream>
#include<unordered_set>
#include <queue>
#include<cstdio>

using namespace std;

const int maxN=100000;
const unsigned long long modN=1000000007;
// 4*x+3
// 8*x+7


int main(){
  long x0, tmp;
  cin >>x0;
  unordered_set<long> hash;
  hash.insert(x0);

  queue<pair<long,int>> q;
  pair<long,int> x(x0, 0);
  q.push(x);
  while(!q.empty()){
    x=q.front();
    printf("%ld %d %d\n", x.first, x.second, (int)q.size());
    q.pop();
    if(x.first%modN==0){
      cout << x.second<<endl;
      return 0;
    }else if(x.second+1<maxN){
      tmp = (x.first*4+3)%modN;
      if(hash.find(tmp)==hash.end()){
        hash.insert(tmp);
        pair<long,int> x1(tmp, x.second+1);
        q.push(x1);
      }
      
      tmp = (x.first*8+7)%modN;
      if(hash.find(tmp)==hash.end()){
        hash.insert(tmp);
        pair<long,int> x2(tmp, x.second+1);
        q.push(x2);
      }
    }
  }
  cout << -1 << endl;
}