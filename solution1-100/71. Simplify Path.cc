#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
      vector<string> stack;
      string tmp;

      for(int i=0;i<path.length();++i){
        if(i!=0 && path[i]=='/'){
          // cout << "tmp: " << tmp << endl;
          if(tmp=="/" || tmp=="/."){
            // ignore it
          }else if(tmp=="/.."){
            // if(stack.empty()){
            //   stack.push_back("/");
            // }else{
            //   stack.pop_back();
            // }
            if(!stack.empty()){
              stack.pop_back();
            }
          }else{
            stack.push_back(tmp);
          }

          tmp=path[i];

        }else{
          tmp.push_back(path[i]);
        }
      }
      if(!tmp.empty()){
        // cout << "tmp: " << tmp << endl;
          if(tmp=="/" || tmp=="/."){
            // ignore it
          }else if(tmp=="/.."){
            if(stack.empty()){
              stack.push_back("/");
            }else{
              stack.pop_back();
            }
          }else{
            stack.push_back(tmp);
          }
      }

      string res;
      for(string str:stack){
        res += str;
      }
      if(res.empty()){
        res+="/";
      }
      return res;
    }
};

int main(){
  Solution so;
  cout << so.simplifyPath("/home/") << endl;          //  "/home"
  cout << so.simplifyPath("/a/./b/../../c/") << endl; //  "/c"
  cout << so.simplifyPath("/../") << endl;            //  "/"
  cout << so.simplifyPath("/") << endl;               //  "/"
  cout << so.simplifyPath("/...") << endl;            //  "/..."
  cout << so.simplifyPath(
    "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") 
    << endl; // "/e/f/g"
}