#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;

int idx[N+5], re[N+5];
string names[N+5], items[N+5], ranks[N+5];
map<string,int> item2prize;
map<string,string> name2item, item2name;
vector<pair<int,pair<string,string>>> vec; //prize name item

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        idx[i] = i;//i-th person at i-th node
        re[i] = i;//i-th node has i-th person
        cin>>names[i];
    }
    for(int i=1;i<=n;i++){
        cin>>items[i];
        cin>>item2prize[items[i]];
    }
    while(m--){
        int u; cin>>u;
        int v = u+1;
        swap(re[u],re[v]);
    }
    for(int i=1;i<=n;i++){
        // cout<<re[i]<<' ';
        vec.push_back({item2prize[items[i]],{names[re[i]],items[i]}});
    }
    sort(vec.begin(),vec.end(),greater<pair<int,pair<string,string>>>());
    for(int i=0;i<n;i++){
        ranks[i+1] = vec[i].second.first;
        name2item[vec[i].second.first] = vec[i].second.second;
        // item2name[vec[i].second.second] = vec[i].second.first;
    }
    // cout<<'\n';
    while(q--){
        // cout<<">> ";
        string cmd, name;
        int rank;
        cin>>cmd;
        if(cmd == "name"){
            cin>>name;
            cout<<name2item[name]<<' '<<item2prize[name2item[name]]<<'\n';
        }else if(cmd == "rank"){
            cin>>rank;
            cout<<ranks[rank]<<' '<<name2item[ranks[rank]]<<'\n';
        }
    }
}
