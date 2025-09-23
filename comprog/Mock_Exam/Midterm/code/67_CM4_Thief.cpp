#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000;

int a[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m,sum=0; cin>>n>>m;
    for(int i=1;i<=n&&cin>>a[i];i++) sum += a[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(sum-a[i]-a[j] == m){
                cout<<i-1<<' '<<a[i]<<'\n';
                cout<<j-1<<' '<<a[j]<<'\n';
                return 0;
            }
        }
    }
}