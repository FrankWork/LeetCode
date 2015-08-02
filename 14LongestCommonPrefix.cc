/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)return "";
        bool flag=true;
        int i=0;
        for(;flag && i<strs[0].length();++i){
            for(int j=1;j<strs.size();++j){
                if(i>=strs[j].length()|| strs[0][i]!=strs[j][i])
                {
                    flag=false;
                    --i;
                    break;
                }
            }
        }

        return strs[0].substr(0,i);
    }
};

int main()
{
    vector<string> strs;//={"abcf","abcd","abcabc"};
    Solution so;
    cout <<so.longestCommonPrefix(strs)<<endl;
    return 0;
}
