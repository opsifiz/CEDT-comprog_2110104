#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

set<string> vis, vis1, vis2, vis0;
map<string,vector<string>> g;
vector<string> input;

int main(){
    string u, v;
    while(cin>>u>>v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis.insert(u);
    for(string v : g[u]) vis1.insert(v);
    for(string u : vis1){
        for(string v : g[u]){
            vis2.insert(v);
        }
    }
    for(string v : vis0) vis.insert(v);
    for(string v : vis1) vis.insert(v);
    for(string v : vis2) vis.insert(v);
    for(string u : vis) cout<<u<<'\n';
}