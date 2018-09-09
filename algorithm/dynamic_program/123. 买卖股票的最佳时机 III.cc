#include "../template.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        第一次交易：
           sell1(i) 前i天卖的最佳利润， buy1(i)  前i天买的最佳利润
           sell1(i) = max(sell1(i-1), buy1(i-1)+price)
           buy1(i) = max(buy1(i-1), -price)
        第二次交易：
           sell2(i) 前i天卖的最佳利润， buy2(i)  前i天买的最佳利润
           sell2(i) = max(sell2(i-1), buy2(i-1)+price)
           buy2(i) =  max(buy2(i-1),  sell1(i-1)-price)
        */
       int sell1 = 0, buy1 = INT_MIN;
       int sell2 = 0, buy2 = INT_MIN;
       
       for(int price: prices){
         sell1 = max(sell1, buy1+price);
         buy1 = max(buy1, -price);
         sell2 = max(sell2, buy2+price);
         buy2 = max(buy2, sell1-price);
       }
       return sell2;
    }
};

int main(){
  Solution so;

  vector<int> a{3,3,5,0,0,3,1,4};
  cout << so.maxProfit(a) << endl;
}