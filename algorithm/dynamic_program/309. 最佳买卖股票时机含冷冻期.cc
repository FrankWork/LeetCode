#include "../template.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* 三个状态，买入，卖出，冷冻
           买之前要卖出，卖出之后要冷冻

           buy(i)   前i天最后一个动作为买的最大收益, 并不是第i天买入
           sell(i)  前i天最后一个动作为卖的最大收益

           buy(i) = max( buy(i-1), sell(i-2)-price ) # max(i天不买， 买)
           sell(i) = max(sell(i-1), buy(i-1)+price ) # max(i天不卖， 卖)
        */
       int n=prices.size();
       vector<int> buy(n+2), sell(n+2);
       buy[1] = INT_MIN;

       for(int i=2;i<=n+1;++i){
         int price = prices[i-2];
         buy[i]=max(buy[i-1], sell[i-2]-price);
         sell[i]=max(sell[i-1], buy[i-1]+price);
       }
        // print(buy);
        // print(sell);
       return sell[n+1];
    }
};

int main(){
  Solution so;
  vector<int> a1{1,2,3,0,2};
  cout << so.maxProfit(a1) << endl;//3

  vector<int> a2{1};
  cout << so.maxProfit(a2) << endl;//0

  vector<int> a3{1, 2};
  cout << so.maxProfit(a3) << endl;//1
}
