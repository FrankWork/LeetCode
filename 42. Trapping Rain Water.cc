#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int l=-1, r=-1;
      bool ascent=true;
      int sum=0, min;
      
      for(int i=1;i<height.size();i++){
        if(height[i] < height[i-1]){
          if(ascent==true){
            if(l==-1){
              l=i-1;
            }else if(r==-1){
              r=i-1;

              // cout << l << " " << r << endl;
              min = height[l]<height[r]?height[l]:height[r];
              sum += (r-l-1)*min;
              for(int j=l+1;j<r;j++){
                if(height[j] > min){
                  sum -= min;
                }else{
                  sum -= height[j];
                }
              }
              
              l=r;
              r=-1;
            }
            ascent=false;
          }
        }else if(height[i]>height[i-1]){
          if(ascent==false){
            ascent=true;
          }
        }
      }
      if(l!=-1){
        r=height.size()-1;
        
        // cout << l << " " << r << endl;
        min = height[l]<height[r]?height[l]:height[r];
        sum += (r-l-1)*min;
        for(int j=l+1;j<r;j++){
          if(height[j] > min){
            sum -= min;
          }else{
            sum -= height[j];
          }
        }
        
        l=r;
        r=-1;
      }
      return sum;
    }
};

int main(){
  Solution so;
  vector<int> nums={0,1,0,2,1,0,1,3,2,1,2,1};// 6
  int result = so.trap(nums);
  cout << result << endl << endl;

  vector<int> nums1={};// 0
  result = so.trap(nums1);
  cout << result << endl << endl;

  vector<int> nums2={2,0,2};// 2
  result = so.trap(nums2);
  cout << result << endl << endl;
  
  
  vector<int> nums3={5,4,1,2};// 1
  result = so.trap(nums3);
  cout << result << endl << endl;

  vector<int> nums4={5,2,1,2,1,5};// 14
  result = so.trap(nums4);
  cout << result << endl << endl;
}