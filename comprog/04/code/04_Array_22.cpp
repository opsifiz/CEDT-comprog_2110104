#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;

string a[N+5], b[N+5];

int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    char c;
    while(cin>>c){
        if(c == 'C'){
            // cout<<"C\n";
            for(int i=1;i<=n;i++) b[i] = a[i];
            for(int i=1;i<=n/2;i++) a[i] = b[n/2+i];
            for(int i=n/2+1;i<=n;i++) a[i] = b[i-n/2];
        }else if(c == 'S'){
            // cout<<"S\n";
            for(int i=1;i<=n;i++) b[i] = a[i];
            for(int i=1, l=1, r=n/2+1;i<=n;i+=2,l++,r++) a[i] = b[l], a[i+1] = b[r];
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
}
/*

a 2 3 4 5 6 7 8 9 0
a 3 5 7 9 2 4 6 8 0


7 -> 2
8 -> 4
9 -> 6
0 -> 8
A -> 0
B -> B
*/