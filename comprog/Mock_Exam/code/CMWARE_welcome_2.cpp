#include<bits/stdc++.h>
using namespace std;

const int N = 100;

int board[N+5][N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }
    int cmd, a, b, k;
    while(cin>>cmd){
        if(cmd == -1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<board[i][j]<<' ';
                }
                cout<<'\n';
            }
            break;
        }
        if(cmd == 1){
            cin>>a>>k;
            for(int j=1;j<=m;j++) board[a][j] *= k;
        }else if(cmd == 2){
            cin>>a>>b>>k;
            for(int j=1;j<=m;j++) board[a][j] += k*board[b][j];
        }else if(cmd == 3){
            cin>>a>>b;
            for(int j=1;j<=m;j++) swap(board[a][j],board[b][j]);
        }
    }
}