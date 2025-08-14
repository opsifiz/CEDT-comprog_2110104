#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int l, r;
    cin>>l>>r;
    int ind = 9, lim = 9, n=1;
    while(ind < l){
        ind = ind*10+9;
        n++;
    }
    while(lim < r){
        lim = lim*10+9;
    }
    lim/=10;
    // cout<<l<<' '<<ind<<' '<<lim<<' '<<r<<'\n';
    int sum = 0;
    while(ind < r){
        int d = ind-l+1;
        sum += d*n;
        // cout<<l<<' '<<ind<<' '<<d*n<<'\n';
        l = ind+1;
        ind = ind*10+9;
        n++;
    }
    sum += (r-l+1)*n;
    cout<<sum;
}