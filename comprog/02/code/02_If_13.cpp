#include<iostream>
#include<cmath>
using namespace std;

void swap(float &a, float &b){
    float temp = a;
    a = b;
    b = temp;
}

int main(){
    float a, b, c, d;
    cin>>a>>b>>c>>d;
    float sum= a+b+c+d;
    if(a > b){
        swap(a,b);
    }
    if(a > c){
        swap(a,c);
    }
    if(a > d){
        swap(a,d);
    }
    if(b > c){
        swap(b,c);
    }
    if(b > d){
        swap(b,d);
    }
    if(c > d){
        swap(c,d);
    }
    sum = sum-a-d;
    sum /= 2;
    cout<<round(sum*100.0)/100.0;
}