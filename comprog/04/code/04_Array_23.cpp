#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5], b[N+5];
map<string,int> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int sum = 0;
    string t;
    int n, m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t>>m;
        mp[t] = m;
    }
    cin>>t;
    string cur = t.substr(4,2);
    while(cin>>t){
        string sub = t.substr(4,2);
        sum += (mp[sub])*(cur!=sub);
        cur = sub;
    }
    cout<<sum;
}