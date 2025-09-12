#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000;

int a[N+5];

bool cal(vector<int> a, vector<int> b){
    int n = a.size();
    int m = b.size();
    if(n != m){
        cout<<"bad";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(a[i] == b[i]) continue;
        if(a[i] > b[i]) return 1;
        return 0;
    }
    return 0;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin>>n>>k;
    int st = -1, mx = 0, mx_sz = 0;
    vector<int> res;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int sum = 0;
        int sz = 0;
        vector<int> cur;
        for(int j=i;j<=n;j++){
            if(a[j] > a[i]) break;
            if(sz + 1 > k) break;
            sum += a[j];
            sz++;
            cur.push_back(a[j]);

        }
        if(sum > mx){
            mx = sum;
            st = i;
            mx_sz = sz;
            res = cur;
        }else if(sum == mx && sz > mx_sz){
            mx_sz = sz;
            st = i;
            res = cur;
        }else if(sum == mx && sz == mx_sz && cal(cur, res)){
            st = i;
            res = cur;
        }
    }
    // cout<<"res : ";
    cout<<mx<<'\n';
    // cout<<st<<' '<<mx_sz<<'\n';
    for(int i=st;i<st+mx_sz;i++) cout<<a[i]<<' ';
}