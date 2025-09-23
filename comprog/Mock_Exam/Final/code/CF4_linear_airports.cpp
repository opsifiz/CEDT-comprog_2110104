#include<bits/stdc++.h>
#define int long long
using namespace std;

map<string,string> mp;
bool lg = 0;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    for(int i=1;i<=n;i++){
        string a, b;
        cin>>a>>b;
        mp[a] = b;
    }
    for(int ind=0;ind<q;ind++){
        string u, v;
        string cmd;
        cin>>cmd;
        if(cmd == "MERGE"){
            cin>>u>>v;
            if(u > v) swap(u,v);
            mp[u] += mp[v];
            ind--;
            continue;
        }
        u = cmd;
        cin>>v;
        string node_u = u.substr(0,3), node_v = v.substr(0,3);
        int idx_u = 0, idx_v = 0;
        for(int i=4;i+1<u.size();i++){
            idx_u = idx_u*10+u[i]-'0';
        }
        for(int i=4;i+1<v.size();i++){
            idx_v = idx_v*10+v[i]-'0';
        }
        // cout<<node_u<<' '<<idx_u<<' '<<node_v<<' '<<idx_v<<'\n';
        // if(mp[node_u][idx_u] == '0') for(;;);
        int sz = mp[node_v].size();
        bool cancel = 1;
        if(node_u != node_v || idx_u != idx_v){
            if(mp[node_v][idx_v] == '0'){
                mp[node_v][idx_v] = '1';
                mp[node_u][idx_u] = '0';
                continue;
            }
            for(int d=1;idx_v-d>=0||idx_v+d<sz;d++){
                if(idx_v-d>=0 && (mp[node_v][idx_v-d] == '0' || (node_u == node_v && idx_u == idx_v-d))){
                    mp[node_u][idx_u] = '0';
                    mp[node_v][idx_v-d] = '1';
                    cancel = 0;
                    
                    cout<<ind<<" SHIFT "<<node_v<<"["<<idx_v-d<<"]\n";
                    lg = 1;
                    
                        // if(node_v == "BBB" && idx_v == 3){
                    //     cout<<"a"<<mp[node_v]<<'\n';
                    // }
                    break;
                }else if(idx_v+d<sz && (mp[node_v][idx_v+d] == '0' || (node_u == node_v && idx_u == idx_v+d))){
                    mp[node_u][idx_u] = '0';
                    mp[node_v][idx_v+d] = '1';
                    cancel = 0;
                    
                    cout<<ind<<" SHIFT "<<node_v<<"["<<idx_v+d<<"]\n";
                    lg = 1;
                    
                        // if(node_v == "BBB" && idx_v == 3){
                    //     cout<<"b"<<mp[node_v]<<'\n';
                    // }
                    break;
                }
            }
            if(cancel){
                cout<<ind<<" CANCEL\n";
                lg = 1;
            }
        }
    }
    if(!lg) cout<<"NO CHANGE";
}