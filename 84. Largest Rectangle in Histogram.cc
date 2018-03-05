#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

template<class T>
void print(vector<T> &vec){
    for(T i: vec){
        cout << i << " ";
    }
    cout << '\n';
}

template<class T>
void print(vector<vector<T>> &matrix){
    for(auto& vec: matrix){
        print(vec);
    }
}

class Solution {
public:
    // time limit exceeded
    int largestRectangleArea_dp(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        vector<vector<int>> minH(n, vector<int>(n, 0));
        for(int i=0;i<n;++i){
            minH[i][i]=heights[i];
            area = max(area, minH[i][i]);
        }
        for(int l=0;l<n;++l){
            for(int r=l+1;r<n;++r){
                minH[l][r] = min(minH[l][r-1], heights[r]);
                area = max(area, minH[l][r]*(r-l+1));
            }
        }
        // print(minH);
        return area;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0, h, w;
        
        
        return area;
    }
};

int main(){
  Solution so;
  vector<int> heights{
      // 2,1,5,6,2,3 // 10
      2,1,2 // 3
    }; 
//   vector<int> heights;
//     for(int i=0;i<=19999;++i)
//         heights.push_back(i);// 100000000
  cout << so.largestRectangleArea(heights) << endl; 
  
}