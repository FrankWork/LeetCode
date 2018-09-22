#include "../template.h"


class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i=num1.length()-1,j=num2.length()-1, r=0;
        while(i>=0 && j>=0){
            // printf("r: %d\n", r);
            int t = num1[i]+num2[j]-'0'*2 + r;
            res.push_back(t%10+'0');
            r=t/10;
            i--;j--;
        }
        while(i>=0){
            // printf("r: %d\n", r);
            
            int t = num1[i]-'0' + r;
            res.push_back(t%10+'0');
            r=t/10;
            i--;
        }
        while(j>=0){
            // printf("r: %d\n", r);
            
            int t = num2[j]-'0' + r;
            res.push_back(t%10+'0');
            r=t/10;
            j--;
        }
        if(r!=0){
            res.push_back(r+'0');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution so;
    cout << so.addStrings("1", "2") << endl;
    cout << so.addStrings("1", "9") << endl;
    cout << so.addStrings("16", "8") << endl;    
    cout << so.addStrings("185", "78") << endl;
    cout << so.addStrings("56", "2345") << endl;
    
    
}