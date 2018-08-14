#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

template <class T>
void print(vector<T> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

int parent(int i){
  return (i-1)/2;
}
int left(int i){
  return 2*i+1;
}
int right(int i){
  return 2*i+2;
}

void maxHeapify(vector<int> &nums, int i, int n){
  // condition: left tree and right tree are valid max heap
  // maxIdx = argmax(nums[i], nums[l], nums[r])
  int l=left(i), r=right(i), maxIdx=i;
  if(l<n && nums[i]<nums[l])maxIdx=l;
  if(r<n && nums[maxIdx]<nums[r])maxIdx=r;
  if(maxIdx!=i){
    swap(nums[i], nums[maxIdx]);
    maxHeapify(nums, maxIdx, n);
  }
}

void buildMaxHeap(vector<int> &nums, int n){
  for(int i=n/2;i>=0;--i){
    maxHeapify(nums, i, n);
  }
}

void heapSort(vector<int>& nums){
  int n=nums.size();
  buildMaxHeap(nums, n);
  for(--n;n>=1;--n){
    swap(nums[n], nums[0]);
    maxHeapify(nums, 0, n);
  }
}

void test_maxHeapify(){
  vector<int> nums{16, 4, 10, 14 ,7, 9,3,2,8,1};
  maxHeapify(nums, 1, nums.size());
  print(nums);
  // 16 14 10 8 7 9 3 2 4 1
}

void test_buildMaxHeap(){
  vector<int> nums{4,1,3,2,16,9,10,14,8,7};
  buildMaxHeap(nums, nums.size());
  print(nums);
}

void test_heapSort(){
  vector<int> nums{4,1,3,2,16,9,10,14,8,7};
  heapSort(nums);
  print(nums);
}

int main(){
  test_maxHeapify();
  test_buildMaxHeap();
  test_heapSort();
}