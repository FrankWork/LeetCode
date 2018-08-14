#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    string LeftRotateString(string str, int k) {
        int n=str.length();
        reverse(str.begin(), str.end());
        reverse(str.begin(), str.begin()+n-k);
        reverse(str.begin()+n-k, str.end());
        return str;
    }
};

int main(){
  Solution so;
  string str="abcXYZdef";
  cout << so.LeftRotateString(str, 3)<<endl;
}
