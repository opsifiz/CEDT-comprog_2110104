#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<pair<int,int>> v;
double sum = 0;
int sz = 0;

int main(){
    int ind, i=-1;
    int Q; cin>>Q;
    string cmd; int n ,t;
    while(Q--){
        cin>>cmd;
        if(cmd == "reset"){
            cin>>n;
        }else if(cmd == "new"){
            cin>>t;
            v.push_back({n,t});
            cout<<">> ticket "<<n++<<"\n";
        }else if(cmd == "next"){
            cout<<">> call "<<v[++i].first<<"\n";
        }else if(cmd == "order"){
            cin>>t;
            int dt = t-v[i].second;
            sum += dt;
            sz += 1;
            cout<<">> qtime "<<v[i].first<<" "<<dt<<"\n";
        }else if(cmd == "avg_qtime"){
            cout<<">> avg_qtime "<<round(sum/sz*100.0)/100.0<<"\n";
        }
    }
}