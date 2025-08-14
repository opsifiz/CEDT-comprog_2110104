#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2000000000;
vector<int> res;

int32_t main(){
    long long n; cin>>n;
    bool f=1;
    for(int i=2;n>1;i++){
        if(n%i==0){
            while(n%i==0){
                if(!f) cout<<"*";
                else f=0;
                cout<<i;
                n/=i;
            }
        }
    }
}