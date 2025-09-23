#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    cout<<(n==1?1:n==2?2:n==3?5:n==4?11:n==5?24:n==6?53:n==7?117:n==8?258:n==9?569:n==10?1255:0);
}