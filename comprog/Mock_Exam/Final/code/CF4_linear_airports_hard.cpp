#include<bits/stdc++.h>
#define int long long
using namespace std;

map<int,tuple<vector<string>,vector<int>,string>> ids;
map<string,int> name2id;

void logging(){
    for(int idx=-10;idx<=10;idx++){
        cout<<"idx = "<<idx<<" : ";
        if(get<2>(ids[idx]) != "*"){
            for(string &name : get<0>(ids[idx])){
                cout<<name<<", ";
            }
            cout<<'\n';
            // cout<<get<2>(ids[idx])<<'\n';
        }
        else cout<<'\n';
    }
    cout<<"----------------\n";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    for(int idx=-10;idx<=10;idx++){
        ids[idx] = {{"xxxx"},{-1},"*"};
    }
    for(int i=1;i<=n;i++){
        string a, b;
        int idx;
        cin>>a>>idx>>b;
        name2id[a] = idx;
        int sz = b.size();
        ids[idx] = {{a},{sz},b};
    }
    // logging();
    bool lg = 0;
    for(int ind=0;ind<q;ind++){
        string u, v;
        string cmd;
        cin>>cmd;
        if(cmd == "MERGE"){
            int k; cin>>k;
            ind--;
            for(int idx=-10;idx<=10;idx++){
                // cout<<idx<<' ';
                if(get<2>(ids[idx]) != "*"){
                    vector<tuple<vector<string>,vector<int>,string>> temp;
                    for(int j=idx;j<=min(10*1LL,idx+k);j++){
                        if(get<2>(ids[j]) != "*"){
                            temp.push_back(ids[j]);
                            ids[j] = {{"xxxx"},{-1},"*"};
                        }
                    }
                    sort(temp.begin(),temp.end());
                    // for(auto &x : temp){
                    //     cout<<get<2>(x)<<' ';
                    // }
                    // cout<<'\n';
                    // cout<<"base : "<<get<2>(temp[0])<<", ";
                    int new_idx = name2id[get<0>(temp[0])[0]];
                    ids[new_idx] = {{},{},""};
                    for(auto &x : temp){
                        int sz = get<0>(x).size();
                        for(int i=0;i<sz;i++){
                            get<0>(ids[new_idx]).push_back(get<0>(x)[i]);
                            get<1>(ids[new_idx]).push_back(get<1>(x)[i]);
                            name2id[get<0>(x)[i]] = new_idx;
                        }
                        get<2>(ids[new_idx]) += get<2>(x);
                    }
                    // cout<<"new_idx = "<<new_idx<<", ";
                    idx += k;
                }
            }
            // cout<<'\n';
            // logging();
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

        int sz;
        sz = get<0>(ids[name2id[node_u]]).size();
        for(int i=0;i<sz;i++){
            if(get<0>(ids[name2id[node_u]])[i] == node_u){
                break;
            }else{
                idx_u += get<1>(ids[name2id[node_u]])[i];
            }
        }
        node_u = get<0>(ids[name2id[node_u]])[0];

        sz = get<0>(ids[name2id[node_v]]).size();
        for(int i=0;i<sz;i++){
            if(get<0>(ids[name2id[node_v]])[i] == node_v){
                break;
            }else{
                idx_v += get<1>(ids[name2id[node_v]])[i];
            }
        }
        node_v = get<0>(ids[name2id[node_v]])[0];

        bool can = 0;
        if(node_u == node_v && idx_u == idx_v){
            can = 1;
            cout<<ind<<" ROUND "<<node_v<<"["<<idx_v<<"]\n";
        }else if(node_u == node_v && idx_u != idx_v){
            //ROUND
            if(get<2>(ids[name2id[node_v]])[idx_v] == '0'){
                cout<<ind<<" ROUND "<<node_v<<"["<<idx_v<<"]\n";
                get<2>(ids[name2id[node_u]])[idx_u] = '0';
                get<2>(ids[name2id[node_v]])[idx_v] = '1';
                lg = 1;
                can = 1;
            }else{
                int sz = get<2>(ids[name2id[node_v]]).size();
                for(int d=1;idx_v-d>=0||idx_v+d<sz;d++){
                    if(idx_v-d>=0 && (get<2>(ids[name2id[node_v]])[idx_v-d] == '0' || idx_u == idx_v-d)){
                        cout<<ind<<" ROUND_SHIFT "<<node_v<<"["<<idx_v-d<<"]\n";
                        get<2>(ids[name2id[node_u]])[idx_u] = '0';
                        get<2>(ids[name2id[node_v]])[idx_v-d] = '1';
                        lg = 1;
                        can = 1;
                        break;    
                    }else if(idx_v+d<sz && (get<2>(ids[name2id[node_v]])[idx_v+d] == '0' || idx_u == idx_v+d)){
                        cout<<ind<<" ROUND_SHIFT "<<node_v<<"["<<idx_v+d<<"]\n";
                        get<2>(ids[name2id[node_u]])[idx_u] = '0';
                        get<2>(ids[name2id[node_v]])[idx_v+d] = '1';
                        lg = 1;
                        can = 1;
                        break;    

                    }
                }
            }
        }else if(node_u != node_v){
            //Normal
            if(get<2>(ids[name2id[node_v]])[idx_v] == '0'){
                get<2>(ids[name2id[node_u]])[idx_u] = '0';
                get<2>(ids[name2id[node_v]])[idx_v] = '1';
                can = 1;
            }else{
                int sz = get<2>(ids[name2id[node_v]]).size();
                for(int d=1;idx_v-d>=0||idx_v+d<sz;d++){
                    if(idx_v-d>=0 && (get<2>(ids[name2id[node_v]])[idx_v-d] == '0')){
                        cout<<ind<<" SHIFT "<<node_v<<"["<<idx_v-d<<"]\n";
                        get<2>(ids[name2id[node_u]])[idx_u] = '0';
                        get<2>(ids[name2id[node_v]])[idx_v-d] = '1';
                        lg = 1;
                        can = 1;
                        break;    
                    }else if(idx_v+d<sz && (get<2>(ids[name2id[node_v]])[idx_v+d] == '0')){
                        cout<<ind<<" SHIFT "<<node_v<<"["<<idx_v+d<<"]\n";
                        get<2>(ids[name2id[node_u]])[idx_u] = '0';
                        get<2>(ids[name2id[node_v]])[idx_v+d] = '1';
                        lg = 1;
                        can = 1;
                        break;    

                    }
                }
            }
        }
        if(!can){
            lg = 1;
            cout<<ind<<" CANCEL\n";
        }
    }
    if(!lg) cout<<"NO CHANGE";
}