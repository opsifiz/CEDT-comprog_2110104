#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

const int N = 100;

int rec[N+5][4];
int valid[N+5][N+5];
int mx = 0;

int chk(int i, int j){
    if(rec[i][0]<rec[j][2]&&rec[j][0]<rec[i][2]&&rec[i][1]<rec[j][3]&&rec[j][1]<rec[i][3]){
        int cur = (min(rec[i][2],rec[j][2])-max(rec[i][0],rec[j][0]))*(min(rec[i][3],rec[j][3])-max(rec[i][1],rec[j][1]));  
        return cur;
    }
    return 0;
}

int32_t main(){
    bool flag = 0;
    int n; cin>>n;
    for(int i=1;i<=n;i++) for(int j=0;j<4;j++) cin>>rec[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            int res = chk(i,j);
            if(res == 0) continue;
            if(res > mx){
                mx = res;
                valid[i][j] = mx;
                flag = 1;
            }else if(res == mx){
                valid[i][j] = mx;
            }
        }
    }
    if(!flag) cout<<"No overlaps";
    else{
        cout<<"Max overlapping area = "<<mx<<"\n";
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(valid[i][j] == mx){
                    cout<<"rectangles "<<i-1<<" and "<<j-1<<'\n';
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<valid[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
    }
}