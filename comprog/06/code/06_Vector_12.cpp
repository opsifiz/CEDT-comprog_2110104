#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v={n};
    while(n != 1){
        if(n&1){
            n = 3*n+1;
        }else{
            n = n/2;
        }
        v.push_back(n);
    }
    int sz = v.size();
    int f=1;
    for(int i=max(0,sz-15);i<sz;i++){
        if(!f) cout<<"->";
        else f = 0;
        cout<<v[i];
    }
}