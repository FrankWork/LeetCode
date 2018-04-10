#include<iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int rev(int x){
    int ans=0;
    while(x>0){
        ans=ans*10+x%10;
        x/=10;
    }
    return ans;
}

int main(){
    int x, y;
    cin >>x>>y;

    cout << rev( rev(x)+rev(y) )<< endl;
    return 0;
}