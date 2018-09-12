#include "../template.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
          buy(i), 前i天，最后一个操作为买入的利润
          sell(i), 前i天，最后一个操作为卖出的利润

          buy(i)  = max(buy[i-1], sell(i-1)-price)
          sell(i) = max(sell[i-1], buy(i-1)+price-fee)
        */

       int n=prices.size();
       vector<int> buy(n+1);
       vector<int> sell(n+1);
       buy[0]=-accumulate(prices.begin(), prices.end(), 0);

       for(int i=1;i<=n;++i){
         int price = prices[i-1];
         buy[i] = max( buy[i-1], sell[i-1]-price);
         sell[i] = max(sell[i-1], buy[i-1]+price-fee);
       }
        // print(buy);
        // print(sell);

       return sell[n];
    }
};

int main(){
  Solution so;
  vector<int> a{1,3,2,8,4,9};
  cout << so.maxProfit(a, 2) << endl;//8

  vector<int> a1{1,3,7,5,10,3};
  cout << so.maxProfit(a1, 3) << endl;//6
}
