#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    int n=numbers.size();
    vector<int> count(n);
    int t;
    for(int i=0;i<n;++i){
      t=numbers[i];
      ++count[t];
      if(count[t]>n/2){
        return t;
      }
    }
    }
};

int main(){
  Solution so;
  vector<int> nums{1,2,3,2,2,2,5,4,2};
  int n = so.MoreThanHalfNum_Solution(nums);
  cout<<n<<endl;
}