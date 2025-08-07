#include<iostream>
#include<cmath>
using namespace std;

struct date{
    int y,m,d;
};

int cal(date a){
    int d = a.d;
    int m = a.m;
    int y = a.y;
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
    return n;
}

int cal_y(date a){
    a.y -= 543;
    return 365 + ((a.y%400==0)||(a.y%4==0&&a.y%100));
}

int main(){
    date a, b;
    cin>>a.d>>a.m>>a.y;
    cin>>b.d>>b.m>>b.y;
    int yna = cal_y(a);
    int cal_a = cal(a);
    int cal_b = cal(b);
    int dy = b.y-a.y-1;
    int t = 365*dy+cal_b+yna-cal_a;
    cout<<t<<' '<<round(sin(2*M_PI*t/23.0)*100)/100<<' '<<round(sin(2*M_PI*t/28.0)*100)/100<<' '<<round(sin(2*M_PI*t/33.0)*100)/100;
}