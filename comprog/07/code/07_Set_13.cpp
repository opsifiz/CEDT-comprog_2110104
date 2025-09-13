#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    set<string> w, l;
    string s, t;
    while(cin>>s>>t){
        w.insert(s);
        l.insert(t);
    }
    bool f = 0;
    vector<string> res;
    for(string x : w){
        if(l.find(x) == l.end()){
            res.push_back(x);
            f = 1;
        }
    }
    sort(res.begin(),res.end());
    if(!f) cout<<"None";
    else{
        for(string x : res){
            cout<<x<<' ';
        }
    }
}