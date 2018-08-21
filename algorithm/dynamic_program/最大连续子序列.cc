#include "template.h"

void getMaxSum(vector<int>&arr){
    /* f(i)表示以第i个数字结尾的子数组的最大和
                  A[0]           i=0
           f(i) = f(i-1) + A[i], f(i-1)>0
                  A[i]           f(i-1)<=0
    */
   int n=arr.size();
   int sum=arr[0], best=sum;
   int first=0, last=n-1, first_=0;
   for(int i=1;i<n;++i){
       if(sum>0){
           sum += arr[i];
       }else{
           sum=arr[i];
           first_=i;
       }
       if(sum>best){
           best=sum;
           last=i;
           first=first_;
       }
   }
   if(best<0){
       best=0; first=0; last=n-1;
   }

   printf("%d %d %d\n", best, arr[first], arr[last]);
}

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;

        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        getMaxSum(arr);
    }
}
// 10
// -22 21 -18 -21 -47 -31 20 18 -42 -35
// 38 20 18

// 10
// 33 36 27 -35 43 -15 36 42 -1 -29
// 167 33 42



// 6
// -2 11 -4 13 -5 -2
// 10
// -10 1 2 3 4 -5 -23 3 7 -21
// 6
// 5 -8 3 2 5 0
// 1
// 10
// 3
// -1 -5 -2
// 3
// -1 0 -2
// 0


// 20 11 13
// 10 1 4
// 10 3 5
// 10 10 10
// 0 -1 -2
// 0 0 0