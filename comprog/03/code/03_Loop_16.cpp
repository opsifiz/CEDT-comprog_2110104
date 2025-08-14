#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    cout<<string(n-1,'.')<<"*\n";
    for(int i=1;i+1<n;i++) cout<<string(n-i-1,'.')<<"*"<<string(2*i-1,'.')<<"*\n";
    cout<<string(2*n-1,'*');
}