#include<bits/stdc++.h>
using namespace std;

int main(){
    double xe, ye,re, rp, xm, ym;
    cin>>xe>>ye>>re>>rp>>xm>>ym;
    double dx = xe-xm;
    double dy = ye-ym;
    double d = sqrt(dx*dx+dy*dy);
    double m = re-rp, n = d-m;
    double xp = (m*xm+n*xe)/(m+n);
    double yp = (m*ym+n*ye)/(m+n);
    cout<<round(xp)<<' '<<round(yp);
}