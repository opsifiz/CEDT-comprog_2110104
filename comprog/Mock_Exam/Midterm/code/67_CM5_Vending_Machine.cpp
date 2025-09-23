#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,sum=0; cin>>k;
    int x;
    string s;
    while(cin>>s){
        s = s.substr(1);
        x = stoi(s);
        sum += x;
    }
    cout<<k*sum;
}