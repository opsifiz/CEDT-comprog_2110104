#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5];

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        double res = a[i];
        for(int j=i-1;j>=1;j--){
            res = a[j]+1/res;
        }
        cout<<setprecision(10)<<res<<'\n';
    }
}