#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x=n, n_rev = 0, i=0;
    while(x>0){
        // cout << n_rev << endl;
        n_rev*=10;
        n_rev += x%10;
        x = x/10;
    }
    cout << n_rev+n;
    return 0;
}