#include<stdio.h>

main(){
    int d,m,y;
    scanf("%d %d %d", &d, &m, &y);
    y -= 543;
    short n = 31;
    if(m == 4 || m == 6 || m == 9 || m == 11){
        n = 30;
    }else{
        if(m == 2){
            n = 28;
            if(y%400 == 0){
                n = 29;
            }
            if(y%4==0 && y%100){
                n = 29;
            }
        }
    }
    d += 15;
    if(d > n){
        d = d-n;
        m++;
    }
    if(m > 12){
        m -= 12;
        y++;
    }
    y += 543;
    printf("%d/%d/%d",d,m,y);
}