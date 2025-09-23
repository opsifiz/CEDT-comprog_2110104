#include <iostream>
using namespace std;

int sol(int a, int k, int m){
    if(k == 0) return 1;
    if(k == 1) return a;
    int res = sol(a,k/2,m);
    if(k&1) return (res*res*a)%m;
    return (res*res)%m;
}

int main(){
    int a, k, m;
    cin>>a>>k>>m;
    a %= m;
    cout<<sol(a,k,m);
}