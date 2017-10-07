/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Minimum Window Substring

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vi;
        if(words.size()==0) return vi;

        map<string, int> conmap;
        for(int i=0;i<words.size();i++){
            conmap[words[i]]++;
        }

        int len2=words[0].length(), len = len2*words.size(),i,j;
        if(s.length()<len)return vi;

        string t,t2;
        map<string, int> ::iterator iter;

        for(i=0;i<=s.length()-len;i++){
            t = s.substr(i,len);
            map<string, int> cntmap;
           for(j=0;j<words.size();j++){
                t2 = t.substr(len2*j,len2);
                if(( iter = conmap.find(t2))!=conmap.end()){
                    cntmap[t2]++;
                }else{
                    break;
                }
           }
           if(conmap==cntmap){
            vi.push_back(i);
           }

        }

        return vi;
    }

};

int main(){
    Solution so;
    //vector<string> words={"foo","bar"};
    //vector<int> vi= so.findSubstring("barfoothefoobarman", words);
    vector<string> words={"foo","bar"};
    vector<int> vi= so.findSubstring("barfoothefoobarman", words);
    for(int i: vi)
        cout <<i<<",";
    cout <<endl;

    return 0;
}
