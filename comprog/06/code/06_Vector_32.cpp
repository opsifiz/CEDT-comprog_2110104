#include<iostream>
#include<vector>
#include<algorithm>
#define inf 1e18
using namespace std;

vector<pair<int,vector<int>>> res;

bool cmp(pair<int,vector<int>> &a, pair<int,vector<int>> &b){
    if(a.first == b.first){
        if(a.second.size() == b.second.size()){
            int sz = a.second.size();
            for(int i=0;i<sz;i++){
                if(a.second[i] != b.second[i]){
                    return a.second[i] < b.second[i];
                }
            }
        }
        return a.second.size() < b.second.size();
    }
    return a.first > b.first;
}

int main(){
    string mode;
    cin>>mode;
    int x;
    while(cin>>x){
        bool f = 0;
        if(mode == "first"){
            for(auto &v : res){
                if(v.first+x <= 100){
                    f = 1;
                    v.second.push_back(x);
                    v.first += x;
                    break;
                }
            }
        }else{
            int mn = inf;
            int idx = -1;
            int sz = res.size();
            for(int i=0;i<sz;i++){
                if(res[i].first+x <= 100){
                    if(mn > 100-res[i].first-x){
                        mn = 100-res[i].first-x;
                        idx = i;
                    }
                }
            }
            if(idx != -1){
                f = 1;
                res[idx].second.push_back(x);
                res[idx].first += x;
            }
        }
        if(!f){
            res.push_back({x,{x}});
        }
    }
    for(auto &v : res){
        sort(v.second.begin(),v.second.end());
    }
    sort(res.begin(),res.end(),cmp);
    for(auto v : res){
        vector<int> x = v.second;
        for(int y : x){
            cout<<y<<' ';
        }
        cout<<'\n';
    }
}