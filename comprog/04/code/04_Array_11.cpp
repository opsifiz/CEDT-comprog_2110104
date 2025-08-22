#include<iostream>
using namespace std;

bool vis[10], f=1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    getline(cin,s);
    for(char c : s){
        if(isdigit(c)){
            vis[c-'0'] = 1;
        }
    }
    for(int i=0;i<10;i++){
        if(!vis[i]){
            if(f) f=0;
            else cout<<',';
            cout<<i;
        }
    }
    if(f) cout<<"None";
}