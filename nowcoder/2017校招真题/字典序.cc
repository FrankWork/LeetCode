#include<iostream>
#include <cstdio>
using namespace std;

long numNode(long p, long n){
    long nNode = 1;
    long level=10, left=p*level, right;
    while(left<=n){
        right = left+level-1;
        if(right<n){
            nNode+=level;
            level*=10;
        }else{
            nNode+=(n-left+1);
            break;
        }
        left=p*level;
    }
    return nNode;
}

int main(){
    long n, m;
    cin >> n >> m;
    long i=1;
    while(m>0){
        long nNode = numNode(i, n);
        // printf("nNode:%ld m:%ld\n", nNode, m);
        if(nNode>=m){
          m-=1;
          if(m==0){break;}
          i*=10; // search subtree
        }else{
          m-=nNode;
          if(m==0) {break;}
          ++i;// search subling
        }
        
    }
    cout << i;
    return 0;
}