#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    vector<pair<string,string>> d;
    string a, b;
    while(cin>>a){
        if(a == "q") break;
        cin>>b;
        d.push_back({a,b});
    }
    while(cin>>a){
        for(int i=0;i<d.size();i++){
            if(d[i].first == a){
                if(d[i].second == "F") d[i].second = "D";
                else if(d[i].second == "D") d[i].second = "D+";
                else if(d[i].second == "D+") d[i].second = "C";
                else if(d[i].second == "C") d[i].second = "C+";
                else if(d[i].second == "C+") d[i].second = "B";
                else if(d[i].second == "B") d[i].second = "B+";
                else if(d[i].second == "B+") d[i].second = "A";
                // else if(d[i].second == "A") d[i].second = "A+";
                // else if(d[i].second == "A+") d[i].second = "INF";
                break;
            }
        }
    }
    for(auto x : d){
        cout<<x.first<<' '<<x.second<<'\n';
    }
}