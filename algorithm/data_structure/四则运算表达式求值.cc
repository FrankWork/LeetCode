#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

/*  四则运算转前、中、后缀表达式：
        将运算按优先级顺序，构造出与表达式相对应的二叉树
        对二叉树进行前、中、后序遍历
        b+c,    +
              b   c

    中缀表达式“9+(3-1)*3+10/2”转化为后缀表达式为“9 3 1- 3 * + 10 2 / +”
*/

string toPostfix(const string & str){
    /* 
        preNum: 前一个输出是否为数字

        遇到数字，preNum为假，输出空格
                 输出数字, 置preNum为真
        其他符号，
          置preNum为假，若以下步骤需要输出符号，则在输出符号前，先输出一个空格
          左括号，入栈
          符号，判断与栈顶元素的优先级
                优先级低于栈顶符号，栈顶元素依次出栈并输出, 直到栈空，当前符号进栈
                      高于栈顶符号，当前符号进栈
          右括号，弹出栈中元素直到左括号
        
        TODO: 负数
            出现 `-`, preNum为假，则为负号，可以输出一个0，将`-`当减法处理 
    */
    stack<char> ops;
    char c;
    string res;
    int idx=0;
    bool preNum=true;
    for(int i=0;i<str.length();++i){
        c = str[i];
        if(c>='0' && c<='9'){
            if(!preNum) res+=' ';
            res+=c;
            preNum=true;
            continue;
        }
        preNum=false;
        
        switch(c){
            case '(': ops.push(c);break;
            case '+':
            case '-':{
                if(!ops.empty() && (ops.top()=='*' || ops.top()=='/')){
                    while(!ops.empty()){
                        res += ' ';
                        res += ops.top();
                        ops.pop();
                    }
                }
                ops.push(c);
                break;  
            }
            case '*':
            case '/': ops.push(c);break;
            case ')':{
                while(ops.top()!='('){
                    res += ' ';
                    res += ops.top();
                    ops.pop();
                }
                ops.pop();// 弹出'('
                break;
            }
        }
    }

    while(!ops.empty()){
        res += ' ';
        res+=ops.top();
        ops.pop();
    }
    return res;
}

int eval(const string &postfix){
    /* 从左到右遍历表达式，
        遇到数字，进栈
        遇到符号，弹出栈顶两个元素并运算，结果入栈
    */
   int res=0;
   bool preNum=true;
   string tmp;
   stack<int> nums;
   for(int i=0;i<=postfix.length();++i){
        if(i==postfix.length() || postfix[i] == ' '){
            if(preNum) nums.push(stoi(tmp));
            else{
                int b=nums.top();
                nums.pop();
                int a=nums.top();
                nums.pop();
                switch(tmp[0]){
                    case '+': nums.push(a+b); break;
                    case '-': nums.push(a-b); break;
                    case '*': nums.push(a*b); break;
                    case '/': nums.push(a/b); break;
                }

            }
            tmp="";
            continue;
        }

        tmp+=postfix[i];
        if(postfix[i] >= '0' && postfix[i] <= '9') preNum=true;
        else preNum=false;
   }
   return nums.top();
}

int main(){
    string postfix = toPostfix("9+(3-1)*3+10/2");//9 3 1 - 3 * + 10 2 / +
    cout << postfix <<endl;
    cout << eval(postfix)<<endl;
}