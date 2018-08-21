#include "template.h"

int binary_search(vector<int>&a, int k){
  /*
    m = (l+r)/2 可能会加法溢出
    推荐使用  m=l+(r-l)/2
    
    循环条件： l<=r
    a(m)==k,  return
    a(m)<k,   l=m+1
    a(m)>k,   r=m-1
  */
  int l=0, r=a.size()-1;

  while(l<=r){
    int m=l+(r-l)/2;
    // m = (l + h) / 2; 
    if(a[m]==k)return m;
    else if(a[m]<k) l=m+1;
    else r=m-1;
  }
  return -1;
}


int binary_search_left_index_of_duplicate(vector<int> &a, int k){
  /* 有重复元素，求要查找元素最左侧的位置
      0,   1,  2     key = 1
      l    m   r 
      l/m  r
           l/r

      停止条件： l<r
      a(m)==k,  r=m,   向左查找
      a(m)<k,   l=m+1, 向右查找
      a(m)>k,   r=m-1  向左查找
  */
  int l=0, r=a.size()-1;
  while(l<r){
    int m=l+(r-l)/2;
    if(a[m]==k) r=m;
    else if(a[m]<k) l=m+1;
    else r=m-1;
  }
  return l;
}