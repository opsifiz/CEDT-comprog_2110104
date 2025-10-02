#include<bits/stdc++.h>
#define int long long
using namespace std;

map<int,int> x, h;
set<int> s;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, k, a, b;
    cin>>m>>k>>a>>b;
    for(int i=1;i<=m;i++){
        int n;
        cin>>n;
        cin>>x[n];
        s.insert(n);
    }
    for(int i=1;i<=k;i++){
        int n;
        cin>>n;
        cin>>h[n];
        s.insert(n);
    }
    for(int n=a;n<=b;n++){
        int sum = 0;
        for(int i : s){
            sum += x[i]*h[n-i];
        }
        cout<<sum<<' ';
    }
}