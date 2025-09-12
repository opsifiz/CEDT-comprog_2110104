#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000;

int a[N+5];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    int cnt = 0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            set<int> vis;
            for(int k=i;k<=j;k++){
                vis.insert(a[k]);
            }
            int sz = j-i+1;
            bool bad = 0;
            if(sz == vis.size()){
                for(int x=1;x<=sz;x++){
                    if(vis.find(x) == vis.end()){
                        bad = 1;
                        break;
                    }
                }
                if(!bad){
                    cnt++;
                    // for(int k=i;k<=j;k++){
                    //     cout<<a[k]<<' ';
                    // }
                    // cout<<'\n';
                }
            }
        }
    }
    cout<<cnt;
}