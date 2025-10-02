#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;

int a[N+5];

map<string,set<int>> mp;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    while(n--){
        string s;
        int m;
        cin>>s>>m;
        mp[s].insert(m);
    }
    int cnt = 0;
    for(auto &x : mp){
        if(x.second.size() == k){
            cnt++;
        }
    }
    cout<<cnt;
}