#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string &str) {
        unordered_map<char, int> m;
        for(auto c:str){
          m[c]++;
        }
        for(int i=0;i<str.length();++i){
          char c=str[i];
          if(m[c]==1)
            return i;
        }
        return 0;
    }
};

int main(){

}