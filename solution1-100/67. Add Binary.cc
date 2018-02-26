#include<string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      string res;
      int n=0, i=a.length()-1, j=b.length()-1;
      
      while(i>=0 && j>=0){
        n = a[i]+b[j]+n-2*'0';
        res.insert(res.begin(), n%2+'0');
        n/=2;
        --i;
        --j;
      }
      while(i>=0){
        n = a[i]+n-'0';
        res.insert(res.begin(), n%2+'0');
        n/=2;
        --i;
      }
      while(j>=0){
        n = b[j]+n-'0';
        res.insert(res.begin(), n%2+'0');
        n/=2;
        --j;
      }
      if(n!=0){
        res.insert(res.begin(), '1');
      }
      
      return res;
    }
};

int main(){
  Solution so;

  cout << so.addBinary("11", "1") << endl;
}