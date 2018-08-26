#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <set>
#include <unordered_set>
#include <queue>

using namespace std;

template<class T>
void print(vector<T>& arr){
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<class T>
void print2d(vector<vector<T>> & matrix){
    for(int i=0;i<matrix.size();++i){
        print(matrix[i]);
    }
}