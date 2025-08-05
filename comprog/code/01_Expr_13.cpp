#include<bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c;
    cin>>a>>b>>c;
    double s = sqrt(b*b-4*a*c);
    double x1 = (-b+s)/(2*a);
    double x2 = (-b-s)/(2*a);
    x1 = round(x1*1e3)/1e3;
    x2 = round(x2*1e3)/1e3;
    cout<<x2<<' '<<x1;
}