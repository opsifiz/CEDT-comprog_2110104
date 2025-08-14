#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    string s;
    cin>>s;
    int n = s.size();
    int l=0, r=0;
    while(l<n){
        int cnt = 0;
        while(r<n && s[l] == s[r]) cnt++, r++;
        cout<<s[l]<<' '<<cnt<<' ';
        l = r;
    }
}