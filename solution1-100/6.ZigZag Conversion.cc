/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include <iostream>
using namespace std;
/**
n=1
return s;

n=2
pyaihrn
aplsiig

N = 4

P      I     G
A   L  S   N
Y A    H I
p      R

n=5




*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;

        int stepG =1+numRows-2;
        int numG = s.length()/(2*numRows-2);
        int r = s.length()%(2*numRows-2);

        int numCols = numG*stepG;
        if(r>0)
            numCols+=(r<=numRows?1:r-numRows+1);
        char buff[numRows][numCols];

        int row=0,col=0,index=0;
        int e = (r==0?numG:numG+1);
        for(int g=0;g<e;g++)
        {
            for(int i=0;i<numRows;i++)
            {
                if(index < s.length())
                 buff[row++][col]=s[index++];
                else
                 buff[row++][col]=' ';
            }
            for(int i=0;i<numRows-2;i++)
            {
                col++;
                if(col>=numCols)
                    break;
                row = numRows;
                for(int j=0;j<numRows;j++)
                {
                    row--;
                    if(i+row==numRows-2 && index<s.length())
                      {
                         buff[row][col]=s[index++];
                      }
                    else
                        buff[row][col]=' ';
                }
            }
            col++;
            row=0;
        }

        char retc[s.length()+1];
        index=0;
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<numCols;j++)
            {
                if(buff[i][j]!=' ')
                {
                    retc[index++]=buff[i][j];
                }
            }
        }
        retc[index]='\0';
        return string(retc);
    }
};

int main(){
    Solution so ;
    cout << so.convert("PAYPALISHIRING", 3);
    cout <<'a';
    return 0;
}
