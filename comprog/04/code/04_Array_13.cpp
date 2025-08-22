#include<iostream>
using namespace std;

const int N = 2e5;

int a[N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cnt=0; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<n;i++) cnt += a[i]>a[i-1]&&a[i]>a[i+1];
    cout<<cnt;
}