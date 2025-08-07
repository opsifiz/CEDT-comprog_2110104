#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin>>a>>b>>c;
    int n = b.size(), m = c.size();
    int x = stoi(a+b+c), y = stoi(a+b);
    int p = x-y,
    q = pow(10,n+m)-pow(10,n);
    int gcd = __gcd(p,q);
    p /= gcd;
    q /= gcd;
    cout<<p<<" / "<<q;
}