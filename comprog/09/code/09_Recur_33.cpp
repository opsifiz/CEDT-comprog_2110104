#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> g[N+5];

bool sol(int u, int des){
    if(u == des) return 1;
    bool res = 0;
    for(int v : g[u]){
        res |= sol(v,des);
    }
    return res;
}

int main(){
    int m, s, t;
    cin>>m>>s>>t;
    while(m--){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
    }
    cout<<(sol(s,t)?"yes":"no");
}