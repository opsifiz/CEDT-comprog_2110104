#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    getline(cin,a);
    getline(cin,b);
    int n = a.size(), m = b.size();
    if(n != m) cout<<"Incomplete answer";
    else{
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += a[i]==b[i];
        }
        cout<<cnt;
    }
}