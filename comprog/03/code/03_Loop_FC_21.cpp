#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    float p; cin>>p;
    float k=1, t=1;
    while(!(1-t>=p)){
        k += 1;
        t = (t*(365-(k-1)))/365;
    }
    cout<<k;
}