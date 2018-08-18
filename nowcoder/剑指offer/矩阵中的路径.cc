#include "template.h"

class Solution {
public:
    /*  回溯法， 从每个位置判断一下是否为开始位置，然后递归找下一个位置
    */
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
      if(str==NULL || rows<1 || cols <1)return false;

      // bool *used = new bool[rows*cols]();
      vector<bool> used(rows*cols, false);
      for(int i=0;i<rows; ++i){
        for(int j=0;j<cols;j++){
            if(backtrace(str, matrix, rows, cols, i,j, used))
              return true;
        }
      }
      return false;
    }

    bool backtrace(char* str, char* matrix, int rows, int cols, 
                  int i, int j, vector<bool>& used){
      // printf("%d %d %c %c\n", i, j, matrix[i*cols+j] ,*str);
      if(*str=='\0') return true;

      if(i<0||i>=rows ||j<0||j>=cols|| used[i*cols+j] ||*str!=matrix[i*cols+j])  
            return false;
     

      used[i*cols+j]=true;
      bool flag = backtrace(str+1, matrix, rows, cols, i+1, j, used) ||
                  backtrace(str+1, matrix, rows, cols, i, j+1, used) ||
                  backtrace(str+1, matrix, rows, cols, i-1, j, used) ||
                  backtrace(str+1, matrix, rows, cols, i, j-1, used);
      used[i*cols+j]=false;
      return flag;
    }


};


int main(){
  Solution so;
  // char matrix[]="ABCESFCSADEE";
  // char s[] = "ABCCED";
  // cout << so.hasPath(matrix, 3, 4, s)<<endl;

  char matrix[]="ABC";
  char s[] = "ABC";
  cout << so.hasPath(matrix, 1, 3, s)<<endl;
}
// ABCE
// SFCS
// ADEE