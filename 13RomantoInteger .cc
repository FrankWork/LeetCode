/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.


*/
#include <iostream>
#include <map>
#include <string>
using  namespace std;

class Solution {
public:
    int romanToInt(string s) {
        //DFA
    num=0, st=0;
    char c;
    for(int i=0;i<s.length();++i)
    {
        c = s[i];
        switch(st){
        case 0:
//cout<<"i:"<<i<<endl;
            if(c=='I')st=1;
            else if(c=='V')st=5;
            else if(c=='X')st=10;
            else if(c=='L')st=50;
            else if(c=='C')st=100;
            else if(c=='D')st=500;
            else if(c=='M')st=1000;
            //else error
            break;
        case 1:
//cout<<"i:"<<i<<endl;
            if(c=='I')st=2;
            else if(c=='V'){st=4;getNumber();}
            else if(c=='X'){st=9;getNumber();}
            else {getNumber();--i;}
            break;
        case 2:
            if(c=='I'){st=3;getNumber();}
            else {getNumber();--i;}
            break;
        case 5:
            if(c=='I'){st=6;}
            else {getNumber();--i;}
            break;
        case 6:
            if(c=='I'){st=7;}
            else {getNumber();--i;}
            break;
        case 7:
            if(c=='I'){st=8;getNumber();}
            else {getNumber();--i;}
            break;
        case 10:
            if(c=='X'){st=20;}
            else if(c=='L'){st=40;getNumber();}
            else if(c=='C'){st=90;getNumber();}
            else {getNumber();--i;}
            break;
        case 20:
            if(c=='X'){st=30;getNumber();}
            else {getNumber();--i;}
            break;
        case 50:
            if(c=='X'){st=60;}
            else {getNumber();--i;}
            break;
        case 60:
            if(c=='X'){st=70;}
            else {getNumber();--i;}
            break;
        case 70:
            if(c=='X'){st=80;getNumber();}
            else {getNumber();--i;}
            break;
        case 100:
            if(c=='C'){st=200;}
            else if(c=='D'){st=400;getNumber();}
            else if(c=='M'){st=900;getNumber();}
            else {getNumber();--i;}
            break;
        case 200:
            if(c=='C'){st=300;getNumber();}
            else {getNumber();--i;}
            break;
        case 500:
            if(c=='C'){st=600;}
            else {getNumber();--i;}
            break;
        case 600:
            if(c=='C'){st=700;}
            else {getNumber();--i;}
            break;
        case 700:
            if(c=='C'){st=800;getNumber();}
            else {getNumber();--i;}
            break;
        case 1000:
            if(c=='M'){st=2000;}
            else {getNumber();--i;}
            break;
        case 2000:
            if(c=='M'){st=3000;getNumber();}
            else {getNumber();--i;}
            break;
        }
    }
    getNumber();
    return num;
    }
private:
    int num,st;
    void getNumber(){num+=st;st=0;}
};

int main(){
    Solution so;
    cout <<so.romanToInt("I")<<endl;//1 = I
cout <<so.romanToInt("II")<<endl;//2 = II
cout <<so.romanToInt("III")<<endl;//3 = III
cout <<so.romanToInt("IV")<<endl;//4 = IV
cout <<so.romanToInt("V")<<endl;//5 = V
cout <<so.romanToInt("V")<<endl;//6 = V
cout <<so.romanToInt("VII")<<endl;//7 = VII
cout <<so.romanToInt("VIII")<<endl;//8 = VIII
cout <<so.romanToInt("IX")<<endl;//9 = IX
cout <<so.romanToInt("X")<<endl;//10 = X
cout <<so.romanToInt("XI")<<endl;//11 = XI
cout <<so.romanToInt("XII")<<endl;//12 = XII
cout <<so.romanToInt("XIII")<<endl;//13 = XIII
cout <<so.romanToInt("XIV")<<endl;//14 = XIV
cout <<so.romanToInt("XV")<<endl;//15 = XV
cout <<so.romanToInt("XVI")<<endl;//16 = XVI
cout <<so.romanToInt("XVII")<<endl;//17 = XVII
cout <<so.romanToInt("XVIII")<<endl;//18 = XVIII
cout <<so.romanToInt("XIX")<<endl;//19 = XIX
cout <<so.romanToInt("XX")<<endl;//20 = XX
cout <<so.romanToInt("XXX")<<endl;//30 = XXX
cout <<so.romanToInt("XL")<<endl;//40 = XL
cout <<so.romanToInt("L")<<endl;//50 = L
cout <<so.romanToInt("LX")<<endl;//60 = LX
cout <<so.romanToInt("LXX")<<endl;//70 = LXX
cout <<so.romanToInt("LXXX")<<endl;//80 = LXXX
cout <<so.romanToInt("XC")<<endl;//90 = XC
cout <<so.romanToInt("C")<<endl;//100 = C
cout <<so.romanToInt("CC")<<endl;//200 = CC
cout <<so.romanToInt("CCC")<<endl;//300 = CCC
cout <<so.romanToInt("CD")<<endl;//400 = CD
cout <<so.romanToInt("D")<<endl;//500 = D
cout <<so.romanToInt("DC")<<endl;//600 = DC
cout <<so.romanToInt("DCC")<<endl;//700 = DCC
cout <<so.romanToInt("DCCC")<<endl;//800 = DCCC
cout <<so.romanToInt("CM")<<endl;//900 = CM
cout <<so.romanToInt("M")<<endl;//1000= M
cout <<so.romanToInt("MM")<<endl;//2000= MM
cout <<so.romanToInt("MMM")<<endl;//3000= MMM


    return 0;
}
