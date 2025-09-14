#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    map<string,string> mp1, mp2;
    int n, m; cin>>n;
    for(int i=1;i<=n;i++){
        string a, b;
        cin>>a>>b;
        mp1[a] = b;
        mp2[b] = a;
    }
    cin>>m;
    while(m--){
        string temp;
        cin>>temp;
        if(mp1.find(temp) != mp1.end()) cout<<mp1[temp]<<'\n';
        else if(mp2.find(temp) != mp2.end()) cout<<mp2[temp]<<'\n';
        else cout<<"Not found\n";
    }
}