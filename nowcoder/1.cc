#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
string solution(int num) {
  int ans=0, t;
  while(num){
   t= num%10;
   num/=10;
   ans+=t*t;
  }

}
/******************************结束写代码******************************/


int main() {
    string res;

    int _num;
    cin >> _num;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = solution(_num);
    cout << res << endl;
    
    return 0;

}
