#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> g[N+5];
vector<int> path;
set<vector<int>> paths;

void sol(int u, int des){
    if(u == des){
        if(paths.find(path) == paths.end()){

            int f = 1;
            for(int x : path){
                if(!f) cout<<" -> ";
                else f = 0;
                cout<<x;
            }
            cout<<'\n';
            paths.insert(path);
        }
        return;
    }
    for(int v : g[u]){
        path.push_back(v);
        sol(v,des);
        path.pop_back();
    }
}

int main(){
    int m, s, t;
    cin>>m>>s>>t;
    while(m--){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
    }
    path.push_back(s);
    for(int i=s;i<=t;i++) sort(g[i].begin(),g[i].end());
    sol(s,t);
    if(!paths.size()) cout<<"no";
}