#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000;

int a[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x; cin>>x;
    double res = sqrt(x*x+cos(x*M_PI/180)*cos(x*M_PI/180))/(sin(x*M_PI/180)+(cos(x*M_PI/180)*cos(x*M_PI/180)*cos(x*M_PI/180))/(x*x+1));
    cout<<fixed<<setprecision(1)<<res;
}