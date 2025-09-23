#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

map<string,int> cnt;
string best;
int mx = 0;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    char c;
    string s;
    while(cin>>c){
        if(c == 'E') break;
        if(c == 'K'){
            cin>>s;
            if(++cnt[s] > mx){
                mx = cnt[s];
                best = s;
            }
        }else if(c == 'P'){
            cin>>s;
            cout<<cnt[s]<<'\n';
        }else if(c == 'H'){
            cout<<best<<'\n';
        }else if(c == 'N'){
            cout<<cnt.size()<<'\n';
        }
    }
}