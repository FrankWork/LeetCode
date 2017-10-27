#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

template<class T>
void print(vector<T>& nums){
    for(int i=0;i<nums.size();i++){
      cout << nums[i]<<"\t";
    }
    cout << endl;
  }

class Solution {
public:

    double myPow(double x, int n){
        // x^100 = x^(2^6+2^5+2^2+1)
        if(n==0) return 1;
        else if(n==INT_MIN) return 1/myPow(x, INT_MAX)*x;
        else if(n<0) return 1/myPow(x,-n);

        int m = static_cast<int>(log2(n));
        vector<int> idx(m+1);
        vector<double> val(m+1);
        idx[0]=1;
        val[0]=x;
        // 0:x, 1:x^2, 2:x^4, .. , m:x^2^m
        for(int i=1;i<=m;i++){
            idx[i] = 2 << (i-1);
            val[i] = val[i-1]*val[i-1];
        }
        // cout << "=== idx and val ===" << endl;
        // cout << "m: " << m << endl;
        // print(idx);
        // print(val);
        // cout << "===================" << endl;

        double res=1;
        for(int i=m;i>=0;i--){
            if(n-idx[i] >= 0){
                res *= val[i];
                n -= idx[i];
            }
        }

        return res;
    }
    
};


int main(){
     Solution so;

//   cout << so.myPow(1, 0)<< "\t"<< pow(1, 0) << endl;
//   cout << so.myPow(2, 2)<< "\t"<< pow(2, 2) << endl;
//   cout << so.myPow(2, 3)<< "\t"<< pow(2, 3) << endl;
//   cout << so.myPow(2, 4)<< "\t"<< pow(2, 4) << endl;
//   cout << so.myPow(2, 5)<< "\t"<< pow(2, 5) << endl;
//   cout << so.myPow(2, 100)<< "\t" << pow(2, 100) << endl;
//   cout << so.myPow(2, -20)<< "\t" << pow(2, -20) << endl;

//   cout << so.myPow(0.00001, 2147483647)<< "\t" << pow(0.00001, 2147483647) << endl;
    
    // cout << so.myPow(1.00000, -2147483648)<< "\t" << pow(1.00000, -2147483648) << endl;
    // cout << so.myPow(-1.00000, -2)<< "\t" << pow(-1.00000, -2) << endl;
    // cout << so.myPow(-1.00000, -3)<< "\t" << pow(-1.00000, -3) << endl;
    // cout << so.myPow(-1.00000, -2147483648)<< "\t" << pow(-1.00000, -2147483648) << endl;

    cout << so.myPow(2.00000, -2147483648)<< "\t" << pow(2.00000, -2147483648) << endl;
    // cout << so.myPow(0.5, -2147483648)<< "\t" << pow(0.5, -2147483648) << endl;

//   cout << log2(static_cast<int>(-2147483648)) << endl;

}