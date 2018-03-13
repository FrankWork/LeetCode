#include <string>
#include <iostream>
using namespace std;

int main(){
    string text;
    cin >> text;
    
    int n=1, len=1, i=1;
    float sum=0;
    if(text.length()<1) cout << text.length();
    for(;i<text.length();++i){
        if(text[i]==text[i-1]){
            ++len;
        }else{
            sum+=len;
            len=1;
            ++n;
        }
    }
    sum+=len;
    // ++n;
    cout << sum/n ;
}