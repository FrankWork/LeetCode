#include <iostream>
#include <vector>
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
int main(){
  string s = "abc", tmp;
  int n = s.length();
  vector<bool> nums(n);
  vector<string> res;
  print(nums);
  do{
    tmp="";
    for(int i=0;i<n;++i){
      if(nums[i])
        tmp+=s[i];
    }
    res.push_back(tmp);
  }while(add(nums));
  for(string & t: res){
    cout << t<<endl;
  }
  
}