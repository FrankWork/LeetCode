#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end());

        int b=-1, e=0;
        for(int i=0;i<=str.size();++i){
          if(i==str.size() || str[i]==' '){
            e=i;
            reverse(str.begin()+b+1, str.begin()+e);
            b=e;
          }
        }
        return str;
    }
};

int main(){
  Solution so;
  string str="student. a am I";
  cout << so.ReverseSentence(str) << endl;
}

