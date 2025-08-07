#include<iostream>
using namespace std;

void swap(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}

main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(a > b){
        swap(a,b);
    }
    if(a > c){
        swap(a,c);
    }
    if(a > d){
        swap(a,d);
    }
    if(a > e){
        swap(a,e);
    }
    if(b > c){
        swap(b,c);
    }
    if(b > d){
        swap(b,d);
    }
    if(b > e){
        swap(b,e);
    }
    if(c > d){
        swap(c,d);
    }
    if(c > e){
        swap(c,e);
    }
    cout<<c;
}