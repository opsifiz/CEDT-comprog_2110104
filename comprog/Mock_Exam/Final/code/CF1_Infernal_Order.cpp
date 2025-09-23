#include<bits/stdc++.h>
using namespace std;

map<string,vector<string>> g;
map<string,int> val;

set<string> s;

void dfs(string u, string p, int cur){
    if(cur <= val[u]) return;
    s.insert(u);
    cur -= val[u];
    for(string v : g[u]){
        if(v == p) continue;
        dfs(v,u,cur);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string u;
        int x, c;
        cin>>u>>x>>c;
        val[u] = x;
        while(c--){
            string v; cin>>v;
            g[u].push_back(v);
        }
    }
    string p;
    int x;
    cin>>p>>x;
    dfs(p,p,x);
    cout<<s.size()<<'\n';
    for(string node : s){
        cout<<node<<'\n';
    }
}