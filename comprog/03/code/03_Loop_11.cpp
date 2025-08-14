#include<bits/stdc++.h>
using namespace std;
int main(){
    float sum, a;
    int n=0;
    while(cin>>a){
        if(a == -1) break;
        sum += a;
        n++;
    }
    if(n) cout<<round((sum/n)*100)/100;
    else cout<<"No Data";
}