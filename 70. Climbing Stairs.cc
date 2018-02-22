#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps{1,1};
        if(n<=1){return steps[n];}

        for(int i=2;i<=n;++i){
          steps.push_back(steps[i-1]+steps[i-2]);
        }
        return steps[n];
    }
};

int main(){
  Solution so;
  cout << so.climbStairs(2) << endl;
  cout << so.climbStairs(3) << endl;

}