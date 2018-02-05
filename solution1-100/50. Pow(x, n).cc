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
    double myPow(double x, int n) {
        if (n < 0) return 1 / power(x, -n);
        return power(x, n);
    }
    double power(double x, int n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0) return half * half;
        return x * half * half;
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