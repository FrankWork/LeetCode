#include <iostream>
#include <string>

using namespace std;

bool valid(const string& a){
    int n=a.length();
    for(int i=0;i<n/2;++i){
        if(a[i]!=a[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string a,b;
    cin >> a>>b;
    int n = a.length(), sum=0;
    for(int i=0;i<=n;++i){
        string tmp = a.substr(0,i)+b+a.substr(i,n-i);
        cout << tmp <<endl;
        if(valid(tmp)){
            ++sum;
        }
    }
    cout << sum <<endl;
    return 0;
}