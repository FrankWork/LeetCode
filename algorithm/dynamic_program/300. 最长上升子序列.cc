#include "../template.h"


  class Solution {
  public:
      int lengthOfLIS(vector<int>& a) {
          /* dp(i) 以i位置结尾的最长递增序列的长度
            dp(i) = max( dp(j) )+1

            O(n^2)

            扩展： 二分查找 O(nlogn)
          */
        int n=a.size();
        if(n==0)return 0;
        vector<int> dp(n);
        dp[0]=0;

        for(int i=0;i<n;++i){
          dp[i]=1;
          for(int j=0;j<i;j++){
            if(a[i]>a[j])
                dp[i]=max(dp[i], dp[j]+1);
          }
        }
        //  print(dp);
        int res=0;
        for(int v:dp)
          res=max(res, v);
        return res;
      }
  };


int main(){
  Solution so;
  // vector<int> a{10,9,2,5,3,7,101,18};//4
  // vector<int> a{2,2};//1
  vector<int> a{3,1,2};//2
  
  
  cout << so.lengthOfLIS(a)<<endl;
}