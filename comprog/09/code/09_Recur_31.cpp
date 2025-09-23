#include<iostream>
#include<set>
using namespace std;

set<string> all;
int n;

void sol(string s, int i=0){
    if(i == n){
        all.insert(s);
        return;
    }
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        sol(s,i+1);
        swap(s[i],s[j]);
    }
}

int main(){
    string s; cin>>s;
    n = s.size();
    sol(s);
    for(string x : all) cout<<x<<' ';
}