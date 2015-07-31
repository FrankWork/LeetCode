/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char,int> c_i_map;
        int lenCur=0;
        int lenMax=0;
        int s_pos=0;

        for(int i=0;i< s.length();i++)
        {
            auto it = c_i_map.find(s[i]);
            if(it ==c_i_map.end() || it->second < s_pos)
            {
                c_i_map[s[i]] = i;
                lenCur++;
            }
            else
            {
                if(lenMax < lenCur)
                {
                    lenMax = lenCur;
                }
                s_pos = c_i_map[s[i]]+1;
                lenCur = i-s_pos+1;
                c_i_map[s[i]]=i;///
            }
        }
        if(lenMax < lenCur)
            lenMax = lenCur;
        return lenMax;
    }
};


int main(){
    string s = "bbb";
    Solution so;
    cout << so.lengthOfLongestSubstring(s)<<endl;
    s = "abcabcbb";
    cout << " " << endl;
    cout << so.lengthOfLongestSubstring(s)<<endl;
    s = "c";
    cout << " " << endl;
    cout << so.lengthOfLongestSubstring(s)<<endl;

}
