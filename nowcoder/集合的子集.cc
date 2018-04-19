#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

template<class T>
void print2d(vector<vector<T>> &matrix){
  for(auto & vec:matrix){
    print(vec);
  }
}

bool add(vector<bool>& nums){
  int n = nums.size();
  for(int i=n-1;i>=0;--i){
    nums[i]= !nums[i];
    if(nums[i]){
      return true;
    }
  }

  return false;
}

class Subset {
public:
    vector<vector<int> > getSubsets(vector<int> A, int n) {
        // write code here
        sort(A.begin(), A.end(), greater<int>());
        vector<bool> state(n);
        vector<vector<int>> res;
        while(add(state)){
          vector<int> tmp;
          for(int i=0;i<n;++i){
            if(state[i])
              tmp.push_back(A[i]);
          }
          res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
  vector<int> A{0, 1};
  Subset s;  
  auto x = s.getSubsets(A, 2);
  print2d(x);
}