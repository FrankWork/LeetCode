#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


void print(vector<int> & nums){
  for(int i=0;i<nums.size();++i){
    if(i!=0) cout << " ";
    cout << nums[i];
  }
  cout <<endl;
}

vector<int> shuffle(vector<int> &cards){
  int n=cards.size()/2;
  vector<int> res(2*n);
  int j=2*n-1;
  for(int i=0;i<n;++i){
    res[j--] = cards[2*n-i-1];
    res[j--] = cards[n-i-1];
  }
  return res;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;++i){
      int n,k;
      cin >>n>>k;
      // cout <<n<<" "<<k<<endl;
      vector<int> cards(2*n);
      for(int j=0;j<2*n;++j){
        cin>>cards[j];
      }
      for(int i=0;i<k;++i)
        cards = shuffle(cards);
      print(cards);
    }

    
}