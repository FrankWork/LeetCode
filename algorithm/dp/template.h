#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <unordered_set>

using namespace std;

template<class T>
void print(vector<T>& arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}