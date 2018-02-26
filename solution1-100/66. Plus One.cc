#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& digits){
    for(int i: digits){
      cout << i << " ";
    }
    cout << '\n';
}

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=1;

        for(int i=digits.size()-1;i>=0;--i){
          n = digits[i]+n;
          digits[i] = n%10;
          n = n/10;
        }
        if(n!=0){
          digits.insert(digits.begin(), n);
        }
        return digits;
    }
};

int main(){
  Solution so;

  // vector<int> digits{1,9,9};
  // vector<int> digits{0};
  vector<int> digits{9};
  print(so.plusOne(digits));
}
