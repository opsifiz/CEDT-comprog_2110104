#include<bits/stdc++.h>
using namespace std;

const int N = 500;

char board[N+5][N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) board[i][j] = '-';
    while(q--){
        int x, y, r;
        char c;
        cin>>c>>r>>x>>y;
        x++;
        y++;
        for(int i=max(1,x-r);i<=min(n,x+r);i++){
            for(int j=max(1,y-r);j<=min(m,y+r);j++){
                if(abs(x-i)+abs(y-j) <= r){
                    board[i][j] = c;
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<board[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}