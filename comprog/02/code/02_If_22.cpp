#include<iostream>
using namespace std;

int main(){
    int d,m,y; cin>>d>>m>>y;
    int n = 0;
    if(m>1) n+=31;
    if(m>2) n+=28;
    if(m>3) n+=31;
    if(m>4) n+=30;
    if(m>5) n+=31;
    if(m>6) n+=30;
    if(m>7) n+=31;
    if(m>8) n+=31;
    if(m>9) n+=30;
    if(m>10) n+=31;
    if(m>11) n+=30;
    n += d;
    y-=543;
    if(y%400==0 || (y%4==0 && y%100)){
        if(d==29&&m==2){
            n++;
        }else if(m>2){
            n++;
        }
    }
    cout<<n;
}