#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>
#define data pair<string,pair<double,double>>
using namespace std;

vector<data> d;
set<string> names;

bool cmp(data &a, data &b){
    if(a.second.second == b.second.second) return a.first < b.first;
    return a.second.second > b.second.second;
}

int main(){
    string a; double b;
    while(cin>>a){
        if(a == "END") break;
        cin>>b;
        d.push_back({a,{b,0}});
        names.insert(a);
    }
    int n = d.size();
    while(cin>>a){
        for(int i=0;i<n;i++){
            if(d[i].first == a){
                d[i].second.second += d[i].second.first;
                break;
            }
        }
    }
    sort(d.begin(),d.end(),cmp);
    int cnt = 0;
    for(int i=0;i<min(n,3);i++){
        if(d[i].second.second == 0) break;
        cnt++;
        cout<<d[i].first<<' '<<d[i].second.second<<'\n';
    }
    if(!cnt){
        cout<<"No Sales";
    }
}