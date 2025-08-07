#include<bits/stdc++.h>
using namespace std;

int main(){
    string n; cin>>n;
    int n12 = 0;
    for(int i=0;i<=11;i++){
        n12 += (13-i)*(n[i]-'0');
    }
    n12 = 11 - n12%11;
    n12 %= 10;
    cout<<n[0]<<"-"<<n.substr(1,4)<<"-"<<n.substr(5,5)<<"-"<<n.substr(10,2)<<"-"<<n12;
}