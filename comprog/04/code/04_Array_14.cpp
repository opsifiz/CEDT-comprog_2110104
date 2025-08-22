#include<bits/stdc++.h>
using namespace std;

const int N = 3000;

int a[N+5];
double board[N+5][N+5], qs[N+5][N+5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+board[i][j];
        }
    }
    for(int i=3;i<=n;i++){
        for(int j=3;j<=m;j++){
            double sum = qs[i][j]-qs[i-3][j]-qs[i][j-3]+qs[i-3][j-3];
            double avg = sum*1.0/9;
            cout<<round(avg*100)/100<<' ';
        }
        cout<<'\n';
    }
}