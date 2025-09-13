#include<iostream>
#include<set>
#include<cstring>
using namespace std;

int main(){
    multiset<char> a, b;
    string s, t;
    getline(cin,s);
    getline(cin,t);
    for(char x : s){
        if(x == ' ') continue;
        if('A' <= x && x <= 'Z') x -= 'A'-'a';
        a.insert(x);
    }
    for(char x : t){
        if(x == ' ') continue;
        if('A' <= x && x <= 'Z') x -= 'A'-'a';
        b.insert(x);

    }
    string c, d;
    for(char x : a) c += x;
    for(char x : b) d += x;
    // cout<<c<<'\n'<<d<<'\n';
    if(c == d) cout<<"YES";
    else cout<<"NO";
}