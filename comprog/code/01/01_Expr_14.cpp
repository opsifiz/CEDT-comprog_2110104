#include<bits/stdc++.h>
using namespace std;

int main(){
    short a; cin>>a;
    a = (a-543)%100;
    cout<<(a+a/4+11)%7;
}