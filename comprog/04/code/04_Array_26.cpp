#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

int a[N+5];

int main(){
    int n, r=-1, cnt=0; cin>>n;
    for(int i=1;i<=n*n&&cin>>a[i];i++){
        if(!a[i]){
            r = (i-1)/n;
        }
    }
    for(int i=1;i<=n*n;i++){
        for(int j=i+1;j<=n*n;j++){
            cnt += a[i]>a[j]&&a[j]!=0;
        }
    }
    if((n&1)&&!(cnt&1)) cout<<"YES";
    else if(!(n&1)&&(cnt&1)&&!(r&1)) cout<<"YES";
    else if(!(n&1)&&!(cnt&1)&&(r&1)) cout<<"YES";
    else cout<<"NO";
}