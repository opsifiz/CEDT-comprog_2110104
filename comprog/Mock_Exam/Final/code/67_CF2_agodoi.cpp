#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5;

int a[N+5];

map<int,bool> mp;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2 == 0){
            mp[a[i]/2] = 1;
        }
    }
    for(int i=1;i<=n;i++) cout<<mp[a[i]]<<' ';
}