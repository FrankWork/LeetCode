#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLengths(vector<string> &vec){
    int n=-1, t;
    for(int i=0;i<vec.size();++i){
        t = vec[i].length();
        if(n<=t){
            n=t;
        }else{
            return false;
        }
    }
    return true;
}

bool isLex(string& a, string &b){
    
    for(int i=0; i<a.length() && i<b.length();++i){
        if(a[i]>b[i]){
            return false;
        }else if(a[i]<b[i]){
            return true;
        }
    }
    if(a.length()>b.length()) return false;
    return true;
}

bool isLexicographically(vector<string> &vec){
    for(int i=0;i<vec.size()-1;++i){
        if(!isLex(vec[i], vec[i+1])){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    vector<string> vec;
    cin >>n;
    for(int i=0;i<n;++i){
        string str;
        cin>>str;
        vec.push_back(str);
    }
    bool len = isLengths(vec);
    bool lex = isLexicographically(vec);
    if(len&&lex){
        cout << "both";
    }else if(len){
        cout << "lengths";
    }else if(lex){
        cout << "lexicographically";
    }else{
        cout << "none";
    }
    return 0;
}