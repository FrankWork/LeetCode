#include "template.h"

int LIS(vector<int> &arr){
    /*
    最长递增序列lis
    f(i) 保存以i结尾的lis的最长长度, 而不是保存当前序列的最大lis长度

    f(i): max( f(j) )+1,  0<= j <i 且 arr[i]>arr[j]

    时间复杂度 n^2
    */

    int n = arr.size();
    vector<int> dp(n);
    dp[0] = 1;
    for(int i=1;i<n;++i){
        int gt=0; // greater than
        for(int j=0;j<i;++j){
            if(arr[i]>arr[j]) gt=max(gt, dp[j]);
        }
        dp[i]= gt+1;
    }
    int lis=0;
    for(int i=0;i<n;++i){
        lis=max(lis, dp[i]);
    }
    return lis;
}


// 二分搜索找上界
int binary_search_up(vector<int>&arr, int n, int k){
    int l=0, r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m]==k)return m;
        else if(arr[m]<k) l=m+1;
        else r=m-1;
    }
    return l;
}

int LIS_v2(vector<int> &arr){
    /*
    最长递增序列lis
    f(i)： 所有lis中, lis长度为i时，末尾最小的那个数, f为递增序列

    f(i): f(i+1)=arr[j],    arr[j]>f(i)
          f(k+1)=arr[j],    arr[j]<f(i), arr[j] > max( f(0)...f(k) ), k<i,  k+1为二分查找的上界
            
    时间复杂度 nlogn
    */

    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    int idx=0;

    for(int i=1;i<n;++i){
        if(arr[i] > dp[idx]) {
            // 如果当前数比B中最后一个数还大，直接添加
            dp[++idx]=arr[i];
        }else{
            // 找到替换位置
            int k = binary_search_up(dp, idx, arr[i]);
            dp[k]=arr[i];
        } 
    }
    // print(dp);
    return idx+1;
}




int main(){
    int n;

    // vector<int> arr0{1,2,4,3}; 
    // n=LIS_v2(arr0);  
    // cout<<n<<endl; 

    // vector<int> arr{1,-1,2,-3,4,-5,6,-7}; // 1,2,4,6  
    // n=LIS_v2(arr);  
    // cout<<n<<endl; 

    // vector<int> arr2{3,1,4,1,5,9,2,6,5};// 1,4,5,9
    //                 //  1,1,5,2,5,0,0,0,0
    // n=LIS_v2(arr2);  
    // cout<<n<<endl;

    vector<int> arr3{2,1,4,3,1,5,6};// 1,3,5,6
    n=LIS_v2(arr3);  
    cout<<n<<endl;


}
