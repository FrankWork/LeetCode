#include "../template.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 
          记录当前最小买入价格和最大卖出价格，并更新最佳利润
          profit = max(proft, max_sell - min_buy) 
        */
       int profit=0, sell=INT_MIN, buy=INT_MAX;

       for(int price: prices){
        //  printf("%d, %d\n", buy, sell);
         if(buy>price){
           buy=price;
           sell=buy;
         }
         if(sell<price){
           sell = price;
           profit = max(profit, sell-buy);
         }
       }

       return profit;
    }

    int maxProfit_v2(vector<int>& prices) {
        /* 
          sell1(i) 前i天卖的最佳利润， buy1(i)  前i天买的最佳利润
           sell1(i) = max(sell1(i-1), buy1(i-1)+price)
           buy1(i) = max(buy1(i-1), -price)
        */
       int sell=0, buy=INT_MIN;

       for(int price: prices){
        //  printf("%d, %d\n", buy, sell);
         sell=max(sell, buy+price);
         buy=max(buy, -price);
       }

       return sell;
    }
    
};

int main(){
  Solution so;
  vector<int> a{7,1,5,3,6,4};
  cout << so.maxProfit(a)<<endl;
}