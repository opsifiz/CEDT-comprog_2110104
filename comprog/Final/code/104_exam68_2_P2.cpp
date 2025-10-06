#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10;

int board[N+5][N+5];

int suma, sumb;
int ai, bi, aj, bj;
int mode;


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    cin>>mode;
    int step = n*n;
    int dup = 0;
    for(int ind=0;ind<step;ind++){
        bool cur_dup = 0;
        // cout<<"("<<ai<<","<<aj<<"), ("<<bi<<","<<bj<<")\n";
        if(ind&1) suma += board[ai][aj];
        else suma -= board[ai][aj];

        if(ai == bi && aj == bj){
            dup++;
            cur_dup = 1;
        }

        if((ai%2==0) && aj==n-1){
            ai += 1;
        }else if(ai%2==0){
            aj++;
        }else if((ai%2==1) && aj == 0){
            ai += 1;
        }else if(ai%2==1){
            aj--;
        }

        int value = board[bi][bj];
        if(value%2 == 0){
            if(!cur_dup){
                sumb += value;
            }
                
            bi = ((bi+value)%n+n)%n;
            bj = ((bj+value+1)%n+n)%n;
        }else{
            if(!cur_dup){
                sumb -= value;
            }
                
            bi = ((bi+value)%n+n)%n;
            bj = ((bj-value-1)%n+n)%n;
        }
    }
    if(mode == 1){
        if(suma > sumb){
            cout<<"A ";
        }else if(suma < sumb){
            cout<<"B ";
        }else{
            cout<<"EQUAL ";
        }
        cout<<suma<<' '<<sumb<<'\n';
    }else if(mode == 2){
        cout<<dup<<'\n';
    }
}
