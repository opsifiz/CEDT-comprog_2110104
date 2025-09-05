#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s; cin>>s;
    int n = s.size();
    s += '$';
    vector<string> res;
    for(int i=0;i<=n;i++){
        res.push_back(s);
        // cout<<s<<'\n';
        s += s[0];
        s = s.substr(1);
    }
    sort(res.begin(),res.end());
    for(string x : res) cout<<x.back();
}