#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
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

class Solution {
public:
	void replaceSpace(char *str,int length) {
    for(int i=0;i<length;++i){
      if(str[i]==' '){
        for(int j=length;j>i;--j){
          str[j+2]=str[j];
        }
        length+=2;
        str[i++]='%';
        str[i++]='2';
        str[i]='0';
        // printf("%s\n", str);
        
      }
    }
	}
};

int main(){
  Solution so;
  char str[30]="We Are Happy";
  so.replaceSpace(str, strlen(str));
  printf("%s\n", str);
  return 0;
}