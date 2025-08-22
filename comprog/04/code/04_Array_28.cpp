#include<bits/stdc++.h>
#define inf 1e18
#define int long long
using namespace std;

const int N = 1e6;

int cnt[256];

int32_t main(){
    string s;
    getline(cin,s);
    for(char c : s){
        cnt[tolower(c)]++;
    }
    for(int i='a';i<='z';i++){
        if(cnt[i]){
            cout<<(char)i<<" -> "<<cnt[i]<<'\n';
        }
    }
}