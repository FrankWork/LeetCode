#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

void print(vector<vector<long long>> & matrix){
  for(auto & vec: matrix){
    for(auto val: vec){
      cout << val << "\t";
    }
    cout << endl;
  }
}

template<class T>
T max(T a, T b, T c){
  return max(max(a, b), c);
}
template<class T>
T min(T a, T b, T c){
  return min(min(a, b), c);
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int k,d;
    cin>>k>>d;
     
    vector<vector<long long>> dp_max(n, vector<long long>(k));
    vector<vector<long long>> dp_min(n, vector<long long>(k));
    
    for(int i=0;i<n;++i){
        dp_max[i][0] = a[i];
        dp_min[i][0] = a[i];
    }
    
    for(int i=0;i<n;++i){
        for(int j=1;j<min(i+1, k);++j){
            for(int x=max(i-d, 0);x<i;++x){
              dp_max[i][j] = max(dp_max[i][j], dp_max[x][j-1]*a[i], dp_min[x][j-1]*a[i]);
              dp_min[i][j] = min(dp_min[i][j], dp_max[x][j-1]*a[i], dp_min[x][j-1]*a[i]);
            }
        }
    }
    // print(dp_max);
    // print(dp_min);

    long long max_a=dp_max[n-1][k-1];
    for(int i=k-1;i<n;++i){
        if(max_a < dp_max[i][k-1]) max_a = dp_max[i][k-1];
        if(max_a < dp_min[i][k-1]) max_a = dp_min[i][k-1];
    }
     cout << max_a;
     
    return 0;
}
