#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
      string nums(n, '1');
      for(int i=0;i<n;++i){
        nums[i] += i;
        // nums.push_back('0' + i);
      }

      vector<int> factorial(n, 1);
      for(int i=1;i<n;++i){
        factorial[i] = factorial[i-1]*i;
        // cout << i << " " << factorial[i] << "\n";
      }
      
      --k;// zero indexed
      // cout << k << "\n";
      string perm;
      for(int i=n-1;i>0;--i){
        int idx = k/factorial[i];
        // cout << "k: " << k << " idx: " << idx << " facto: " << factorial[i] <<  "\n";
        perm.push_back(nums[idx]);
        // cout << nums[idx];
        nums.erase(nums.begin()+idx);
        k%=factorial[i];
      }
      perm.push_back(nums[0]);

      // cout << '\n';
        
      return perm;
    }
};

int main(){
  Solution so;

  cout << so.getPermutation(3, 1) << endl;
  cout << so.getPermutation(3, 2) << endl;
  cout << so.getPermutation(3, 3) << endl;
  cout << so.getPermutation(3, 4) << endl;
  cout << so.getPermutation(3, 5) << endl;
  cout << so.getPermutation(3, 6) << endl;
}
