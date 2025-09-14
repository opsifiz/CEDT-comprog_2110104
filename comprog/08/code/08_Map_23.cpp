#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string,int> mp;

int main(){
    string t, p, type, time;
    while(cin>>t>>p>>type>>time){
        int x=0;
        for(int i=0;i<time.size();i++){
            if(time[i] == ':'){
                x = i;
                break;
            }
        }
        int m=0, s=0;
        for(int i=0;i<x;i++){
            m = m*10+time[i]-'0';
        }
        for(int i=x+1;i<time.size();i++){
            s = s*10+time[i]-'0';
        }
        mp[type] += m*60+s;
        // cout<<m<<' '<<s<<'\n';
    }
    vector<pair<int,string>> a;
    for(auto x=mp.rbegin();x!=mp.rend();++x){
        a.push_back({x->second,x->first});
    }
    sort(a.begin(),a.end(),greater<pair<int,string>>());
    for(int i=0;i<min(3,(int)a.size());i++){
        cout<<a[i].second<<" --> "<<(a[i].first)/60<<':'<<(a[i].first)%60<<'\n';
    }
    int cnt = 0;
}