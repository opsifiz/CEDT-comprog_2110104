#include<bits/stdc++.h>
#define inf 1e18
using namespace std;

const int N = 2e5;

int a[N+5], b[N+5];
map<string,int> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<'\n';
    int ind = n;
    while(ind){
        int mx = -inf;
        int idx = -1;
        for(int i=1;i<=ind;i++){
            if(a[i] > mx){
                mx = a[i];
                idx = i;
            }
        }
        if(idx == ind){
            ind--;
            continue;
        }
        if(idx != 1){
            int l = 1, r = idx;
            while(l<r){
                swap(a[l++],a[r--]);
            }
            for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<'\n';
        }
        int l = 1, r = ind;
        while(l<r){
            swap(a[l++],a[r--]);
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<' '; cout<<'\n';
    }
}