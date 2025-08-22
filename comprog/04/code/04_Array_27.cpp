#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

const int N = 1e6;

int board[2][N+5];

int32_t main(){
    int m = -1;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int te, mp;
        cin>>te>>mp;
        board[0][i] = te;
        board[1][i] = mp;
    }
    string s; cin>>s;
    m = s=="Zag-Zig";
    int b = inf, r = -inf;
    for(int i=0;i<n;i++){
        r = max(r,board[(i&1)^m^1][i]);
        b = min(b,board[(i&1)^m][i]);
    }
    cout<<b<<' '<<r;
}