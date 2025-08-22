#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5], stk_l[N+5], stk_r[N+5];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        stk_l[i] = max(stk_l[i-1],a[i]);
    }
    for(int i=n;i>=1;i--){
        stk_r[i] = max(stk_r[i+1],a[i]);
    }
    int sum = 0;
    for(int i=2;i<n;i++) sum += max(0,min(stk_l[i-1],stk_r[i+1])-a[i]);
    // cout<<stk_l[2]<<' '<<a[3]<<' '<<stk_r[4];
    cout<<sum;
}