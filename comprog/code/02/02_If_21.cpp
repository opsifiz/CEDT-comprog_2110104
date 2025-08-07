#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float a;
    bool f = 0;
    cin>>a;
    char c='*';
    if(a >= 1e9) a/=1e9, c='B', f=1;
    else if(a >= 1e6) a/=1e6, c='M', f=1;
    else if(a >= 1e3) a/=1e3, c='K', f=1;
    a = round(a*10)/10.0;
    int temp = (int)(a*10)%10;
    if(a > 5) a = round(a);
    cout<<a;
    if(f) cout<<c;
}