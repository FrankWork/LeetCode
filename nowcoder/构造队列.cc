#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> foo(int n){
  vector<int> res(n, 0);
  int j=-1;
  for(int i=1;i<=n;++i){
    j=(j+1)%n;
    while(res[j]!=0)
      j=(j+1)%n;

    j=(j+1)%n;
    while(res[j]!=0)
      j=(j+1)%n;;
    res[j]=i;
  }
    
    
    return res;
}

void bar(){
  vector<int> vec{3,1,5,2,4};//{4, 1,3,2};
  queue<int> Q;
  for(int val:vec){
    Q.push(val);
  }
  while(!Q.empty())              //队列不空，执行循环

{

    int x=Q.front();            //取出当前队头的值x

    Q.pop();                 //弹出当前队头

    Q.push(x);               //把x放入队尾

    x = Q.front();              //取出这时候队头的值

    printf("%d\n",x);          //输出x

    Q.pop();                 //弹出这时候的队头

}

}
int main(){

    int T;
    int n;
    cin >>T;
    for(int i=0;i<T;++i){
        cin >>n;
        // cout << n << endl;
        vector<int> res = foo(n);
        for(int i=0;i<res.size();++i){
            if(i!=0) cout << " ";
            cout << res[i];
        }
        cout << '\n';
    }
    // bar();
    return 0;
}