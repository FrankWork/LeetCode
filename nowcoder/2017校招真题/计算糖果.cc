#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  int a,b,c,d, A,B,C;
  cin >>a>>b>>c>>d;
  A=(a+c)/2;
  // B=c-A;
  
  B=(b+d)/2;
  C=d-B;
  if(a==A-B && b==B-C && c==A+B && d==B+C){
    printf("%d %d %d\n", A,B,C);
    
  }else{
    cout << "No"<<endl;
  }
  
  return 0;
}