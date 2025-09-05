#include<iostream>
#include<vector>
using namespace std;

const int N = 5;

string board[N+5][N+5];
bool vis[N+5][N+5];
int idx[N+5][N+5];
string h[] = {"X","B","I","N","G","O"};

void logging(){
    cout<<'\n';
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(){
    vis[3][3] = 1;
    for(int i=1;i<=N;i++) cin>>h[i];
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
            if(i!=3||j!=3) board[i][j] = h[j]+board[i][j];
        }
    }
    // logging();
    string s;
    int ind = 1;
    while(cin>>s){
        bool f = 0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(board[i][j] == s){
                    vis[i][j] = 1;
                    idx[i][j] = ind;
                    f = 1;
                    break;
                }
                if(f) break;
            }
            if(f) break;
        }
        vector<vector<string>> res;
        // int mx = -1;
        for(int i=1;i<=N;i++){
            int cur = 0;
            bool can = 1;
            vector<string> temp;
            for(int j=1;j<=N;j++){
                can &= vis[i][j];
                if(!can) break;
                cur = max(cur,idx[i][j]);
                if(board[i][j] != "*") temp.push_back(board[i][j]);
            }
            if(can){
                res.push_back(temp);
                // mx = max(mx,cur);
            }
        }
        for(int j=1;j<=N;j++){
            int cur = 0;
            bool can = 1;
            vector<string> temp;
            for(int i=1;i<=N;i++){
                can &= vis[i][j];
                if(!can) break;
                cur = max(cur,idx[i][j]);
                if(board[i][j] != "*") temp.push_back(board[i][j]);
            }
            if(can){
                res.push_back(temp);
                // mx = max(mx,cur);
            }
        }
        for(int i=1;i<=1;i++){
            int cur = 0;
            bool can = 1;
            vector<string> temp;
            for(int j=1;j<=N;j++){
                can &= vis[j][j];
                if(!can) break;
                cur = max(cur,idx[j][j]);
                if(board[j][j] != "*") temp.push_back(board[j][j]);
            }
            if(can){
                res.push_back(temp);
                // mx = max(mx,cur);
            }
        }
        for(int i=1;i<=1;i++){
            int cur = 0;
            bool can = 1;
            vector<string> temp;
            for(int j=N;j>=1;j--){
                can &= vis[j][N-j+1];
                if(!can) break;
                cur = max(cur,idx[j][N-j+1]);
                if(board[j][j] != "*") temp.push_back(board[j][N-j+1]);
            }
            if(can){
                res.push_back(temp);
                // mx = max(mx,cur);
            }
        }
        // cout<<mx<<'\n';
        if(res.size()){
            cout<<ind<<'\n';
            for(auto r : res){
                bool f = 1;
                for(auto temp : r){
                    if(!f) cout<<", ";
                    else f = 0;
                    cout<<temp;
                }
                cout<<'\n';
            }
            return 0;
        }
        ind++;
    }
}