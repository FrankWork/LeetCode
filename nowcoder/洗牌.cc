#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> & nums){
  for(int n:nums){
    cout << n << " ";

  }
  cout <<endl;
}

int main(){
    int t;
    for(int i=0;i<t;++i){
      int n,k;
      cin >>n>>k;
      cout <<n<<" "<<k<<endl;
      vector<int> cards(2*n);
      for(int j=0;j<2*n;++j){
        cin>>cards[j];
      }
      print(cards);
    }

    
}