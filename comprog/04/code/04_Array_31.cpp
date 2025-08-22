#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

const int N = 2e5;

int a[N+5];

map<int,string> mp;

void init(){
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";
    mp[10] = "ten";
    mp[11] = "eleven";
    mp[12] = "twelve";
    mp[13] = "thirteen";
    mp[14] = "fourteen";
    mp[15] = "fifteen";
    mp[16] = "sixteen";
    mp[17] = "seventeen";
    mp[18] = "eighteen";
    mp[19] = "nineteen";
    mp[20] = "twenty";
    mp[30] = "thirty";
    mp[40] = "forty";
    mp[50] = "fifty";
    mp[60] = "sixty";
    mp[70] = "seventy";
    mp[80] = "eighty";
    mp[90] = "ninety";
    mp[100] = " hundred";
    mp[1e3] = " thousand";
    mp[1e6] = " million";
    mp[1e9] = " billion";
    mp[1e12] = " trillion";
}

string sol(int num, int b){
    if(num == 0) return "";
    if(num <= 20){
        string res = mp[num];
        if(b > 1) res += mp[b];
        return res;
    }
    if(num < 100) return mp[num-(num%10)]+' '+(num%10?mp[num%10]:"")+(b>1?mp[b]:"");
    if(num <1000) return mp[(num%1000)/100]+mp[100]+' '+sol(num%100,b);
    int l = num/1000;
    int r = num%1000;
    string lt = sol(l,b*1e3);
    string rt = sol(r,b);
    return lt+' '+rt;
}

int32_t main(){
    init();
    int num; cin>>num;
    if(num == 0){
        cout<<mp[num];
        return 0;
    }
    cout<<sol(num,1);
}

/*
999999999999999

999 999 999 999 999

*/