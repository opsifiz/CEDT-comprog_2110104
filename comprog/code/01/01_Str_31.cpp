#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    string a, b, c;
    cin>>a>>b>>c;
    int n = b.size(), m = c.size();
    int p, q;
    if(a != "0" && b != "0" && c == "0"){
        q = stoi("1"+string(n,'0'));
        p = stoi(b) + stoi(a)*q;
        int gcd = __gcd(p,q);
        p /= gcd;
        q /= gcd;
        cout<<p<<" / "<<q;
        return 0;
    }
    if(b == c){
        q = stoi(string(n,'9'));
        p = q*stoi(a) +  stoi(b);
    }else{
        q = stoi(string(m,'9')+string(n,'0'));
        p = stoi(b+c) - stoi(b);
        p += stoi(a)*q;
    }
    int gcd = __gcd(p,q);
    p /= gcd;
    q /= gcd;
    cout<<p<<" / "<<q;

}