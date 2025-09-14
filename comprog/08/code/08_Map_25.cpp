#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

map<string,set<string>> mp;
vector<string> ids;
vector<int> res;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string s, t;
        cin>>s;
        while(cin>>t && t!="*"){
            mp[s].insert(t);
        }
        ids.push_back(s);
    }
    string u; cin>>u;
    bool flag = 0;
    for(int i=0;i<n;i++){
        if(ids[i]==u) continue;
        bool f = 0;
        for(string v : mp[ids[i]]){
            if(mp[u].find(v) != mp[u].end()){
                f = 1;
            }
        }
        flag |= f;
        if(f) res.push_back(i);
    }
    if(!flag) cout<<">> Not Found";
    else{
        for(int x : res){
            cout<<">> "<<ids[x]<<'\n';
        }
    }
}