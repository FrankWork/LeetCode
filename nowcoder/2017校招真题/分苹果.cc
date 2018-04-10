#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int> nums(n);
    int mean=0;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        mean+=nums[i];
    }
    if(mean%n!=0){
        cout << -1;
        return 0;
    }
    mean = mean/n;
    vector<int> need(n);
    int times=0;
    for(int i=0;i<n;++i){
      need[i]=nums[i]-mean;
      if(need[i]>0 && need[i]%2==0){
        times+=need[i]/2;
      }else if(need[i]>0 && need[i]%2!=0){
        cout << -1;
        return 0;
      }
      
    }
    cout << times;
    
    
    return 0;
}