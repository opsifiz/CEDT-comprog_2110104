#include<iostream>
#include<map>
#include<set>
#include<cstring>
#include<vector>
using namespace std;

map<string,string> mp;
set<string> vis;
vector<string> seq;

int main(){
    string a, b;
    while(cin>>a>>b){
        if(mp.find(b) == mp.end()) mp[b] = a;
        else mp[b] += ' '+a;
        if(vis.find(b) == vis.end()){
            vis.insert(b);
            seq.push_back(b);
        }
    }
    for(string x : seq){
        cout<<x<<": "<<mp[x]<<'\n';
    }
}