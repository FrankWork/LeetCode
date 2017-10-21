#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
      string buf(num1.size()+num2.size(), '0');

      for(int i=num1.size()-1;i>-1;i--){
        int carry=0;
        for(int j=num2.size()-1;j>-1;j--){
          int temp = (buf[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
          buf[i+j+1]=temp%10+'0';
          carry = temp/10;
        }
        if(carry!=0){
          buf[i]+=carry;
        }
      }
      size_t pos = buf.find_first_not_of("0");
      if(pos!=string::npos){
       return buf.substr(pos); 
      }
      return "0";
    }
};

int main(){
  Solution so;
  string result;

  result = so.multiply("0", "0");
  cout << result <<" " << 0*0 << endl << endl;

  result = so.multiply("0", "1234");
  cout << result <<" " << 0*1234 << endl << endl;

  result = so.multiply("1", "1234");
  cout << result <<" " << 1*1234 << endl << endl;

  result = so.multiply("3", "4");
  cout << result <<" " << 3*4 << endl << endl;

  result = so.multiply("56", "4");
  cout << result <<" " << 56*4 << endl << endl;

  result = so.multiply("56", "34");
  cout << result <<" " << 56*34 << endl << endl;

  result = so.multiply("56", "134");
  cout << result <<" " << 56*134 << endl << endl;

  result = so.multiply("88", "999");
  cout << result <<" " << 88*999 << endl << endl;
  
}
