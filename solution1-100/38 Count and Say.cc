#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
          return "1";
        }
        else if(n==2){
          return "11";
        }

        string str = countAndSay(n-1);
        string ans = "";
        int count = 1, i;
        for(i=1;i<str.size();i++){
          if(str[i] == str[i-1]){
            count++;
          }else{
            ans+=to_string(count)+str[i-1];
            count=1;
          }
        }
        ans+=to_string(count)+str[i-1];
        return ans;
    }
};


int main(){
  Solution so;
  cout << so.countAndSay(1) << endl;
  cout << so.countAndSay(2) << endl;
  cout << so.countAndSay(3) << endl;
  cout << so.countAndSay(4) << endl;
  cout << so.countAndSay(5) << endl;
  cout << so.countAndSay(6) << endl;
  cout << so.countAndSay(7) << endl;
  cout << so.countAndSay(8) << endl;
}