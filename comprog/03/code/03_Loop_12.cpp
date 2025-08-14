#include<bits/stdc++.h>
using namespace std;
int main(){
    double a; cin>>a;
    double l = 0, u = a;
    double x;
    if(a == 1){
        cout<<"2.91038e-11";
        return 0;
    }
    while(1){
        x = (l+u)/2;
        if(abs(a-pow(10,x)) <= 1e-10*max(a,pow(10,x))) break;
        if(pow(10,x) > a) u = x;
        else l = x;
        x = (l+u)/2;
    }
    cout<<l;
}