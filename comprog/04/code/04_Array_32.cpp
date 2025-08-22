#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

const int N = 2e5;

int a[N+5];
int ind[N+5];
int src[N+5];
int dst[N+5];


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ind[i]>>src[i]>>dst[i];
    cin>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        int idx = -1, mn = inf;
        for(int i=1;i<=n;i++){
            int cal = inf;
            if(u <= v && v <= src[i] && src[i] <= dst[i]) cal = min(cal,dst[i]-u+v-u);
            if(u <= src[i] && src[i] <= v && v <= dst[i]) cal = min(cal,dst[i]-u+v-u);
            if(u <= src[i] && src[i] <= dst[i] && dst[i] <= v) cal = min(cal,dst[i]-u+v-u);
            if(src[i] <= u && u <= v && v <= dst[i]) cal = 0;
            if(src[i] <= u && u <= dst[i] && dst[i] <= v) cal = min(cal,v-dst[i]);
            if(src[i] <= dst[i] && dst[i] <= u && u <= v) cal = min(cal,v-dst[i]);
            
            if(v <= u && u <= src[i] && src[i] <= dst[i]) cal = min(cal,dst[i]-u+u-v);
            if(v <= src[i] && src[i] <= u && u <= dst[i]) cal = min(cal,dst[i]-v);
            if(v <= src[i] && src[i] <= dst[i] && dst[i] <= u) cal = min(cal,u-dst[i]+u-v);
            if(src[i] <= v && v <= u && u <= dst[i]) cal = dst[i]-v;
            if(src[i] <= v && v <= dst[i] && dst[i] <= u) cal = min(cal,u-dst[i]+u-v);
            if(src[i] <= dst[i] && dst[i] <= v && v <= u) cal = min(cal,u-dst[i]+u-v);
            
            if(u <= v && v <= dst[i] && dst[i] <= src[i]) cal = min(cal,dst[i]-u+v-u);
            if(u <= dst[i] && dst[i] <= v && v <= src[i]) cal = min(cal,dst[i]-u+v-u);
            if(u <= dst[i] && dst[i] <= src[i] && src[i] <= v) cal = min(cal,dst[i]-u+v-u);
            if(dst[i] <= u && u <= v && v <= src[i]) cal = v-dst[i];
            if(dst[i] <= u && u <= src[i] && src[i] <= v) cal = min(cal,v-dst[i]);
            if(dst[i] <= src[i] && src[i] <= u && u <= v) cal = min(cal,v-dst[i]);
            
            if(v <= u && u <= dst[i] && dst[i] <= src[i]) cal = min(cal,dst[i]-u+u-v);
            if(v <= dst[i] && dst[i] <= u && u <= src[i]) cal = min(cal,dst[i]-v);
            if(v <= dst[i] && dst[i] <= src[i] && src[i] <= u) cal = min(cal,u-dst[i]+u-v);
            if(dst[i] <= v && v <= u && u <= src[i]) cal = 0;
            if(dst[i] <= v && v <= src[i] && src[i] <= u) cal = min(cal,u-dst[i]+u-v);
            if(dst[i] <= src[i] && src[i] <= v && v <= u) cal = min(cal,u-dst[i]+u-v);
            if(cal < mn){
                idx = ind[i];
                mn = cal;
            }else if(cal == mn){
                idx = min(idx,ind[i]);
            }
        }
        cout<<">> "<<idx<<'\n';
        // cout<<mn<<'\n';
    }
}
