#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

template<class T>
void print(vector<T> &vec){
    for(T i: vec){
            cout << i << " ";
        }
        cout << '\n';
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
    }
};

int main(){
  Solution so;
  vector<int> heights{2,1,5,6,2,3};
  cout << so.largestRectangleArea(heights) << endl;
  
}