#include<iostream>
#include<map>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

map<string,string> nisit;
map<string,vector<string>> choose;
map<string,int> subject;
vector<string> ids;
vector<pair<double,string>> score;

int main(){
    int n, m;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s; int num;
        cin>>s>>num;
        subject[s] = num;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string id, a, b, c, d;
        double s;
        cin>>id>>s>>a>>b>>c>>d;
        ids.push_back(id);
        score.push_back({s,id});
        choose[id] = {a,b,c,d};
    }
    sort(score.begin(),score.end(),greater<pair<double,string>>());
    for(auto x : score){
        for(int i=0;i<4;i++){
            if(subject[choose[x.second][i]]){
                subject[choose[x.second][i]]--;
                nisit[x.second] = choose[x.second][i];
                break;
            }
        }
    }
    sort(ids.begin(),ids.end());
    for(string id : ids){
        cout<<id<<' '<<nisit[id]<<'\n';
    }
}