#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

map<string,int> mp;

bool cmp(pair<string,string> &a, pair<string,string> &b){
    // if(mp[a.second] == mp[b.second]) return a.first > b.first;
    return mp[a.second] > mp[b.second];
}

void init(){
    mp["A+"] = 8;
    mp["A"] = 7;
    mp["B+"] = 6;
    mp["B"] = 5;
    mp["C+"] = 4;
    mp["C"] = 3;
    mp["D+"] = 2;
    mp["D"] = 1;
    mp["F"] = 0;
}

int main(){
    init();
    int n; cin>>n;
    vector<pair<string,string>> d(n);
    string a, b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        d[i] = {a,b};
    }
    while(cin>>a){
        int sz = a.size();
        char mode = a[sz-1];
        a = a.substr(0,sz-1);
        for(int i=0;i<d.size();i++){
            if(d[i].first == a){
                if(mode == '+'){
                    if(d[i].second == "F") d[i].second = "D";
                    else if(d[i].second == "D") d[i].second = "D+";
                    else if(d[i].second == "D+") d[i].second = "C";
                    else if(d[i].second == "C") d[i].second = "C+";
                    else if(d[i].second == "C+") d[i].second = "B";
                    else if(d[i].second == "B") d[i].second = "B+";
                    else if(d[i].second == "B+") d[i].second = "A";
                    // else if(d[i].second == "A") d[i].second = "A+";
                    // else if(d[i].second == "A+") d[i].second = "INF";
                }else{
                    /*if(d[i].second == "F") d[i].second = "-INF";
                    else */if(d[i].second == "D") d[i].second = "F";
                    else if(d[i].second == "D+") d[i].second = "D";
                    else if(d[i].second == "C") d[i].second = "D+";
                    else if(d[i].second == "C+") d[i].second = "C";
                    else if(d[i].second == "B") d[i].second = "C+";
                    else if(d[i].second == "B+") d[i].second = "B";
                    else if(d[i].second == "A") d[i].second = "B+";
                    // else if(d[i].second == "A+") d[i].second = "A";
                }
                break;
            }
        }
    }
    sort(d.begin(),d.end(),cmp);
    for(auto x : d){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}