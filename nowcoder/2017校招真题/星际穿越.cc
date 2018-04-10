#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long h;
    cin >>h;
    
    long y;
    double x = (sqrt(1+4*(double)h)-1)/2.0;
    printf("%f %d\n",x , (int)floor(x));
    // cout << (int)floor(x);
    return 0;
}