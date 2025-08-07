#include<iostream>
#include<cmath>
using namespace std;

struct nisit{
    string id;
    float gpa;
    char a,b,c;
    bool valid;
};

int main(){
    nisit a, b;
    cin>>a.id>>a.gpa>>a.a>>a.b>>a.c;
    cin>>b.id>>b.gpa>>b.a>>b.b>>b.c;
    if(a.a != 'A' && b.a !=  'A') cout<<"none";
    a.valid = a.a == 'A' && a.b <= 'C' && a.c <= 'C';
    b.valid = b.a == 'A' && b.b <= 'C' && b.c <= 'C';
    if(a.valid^b.valid){
        if(a.valid) cout<<a.id;
        else cout<<b.id;
    }else if(!a.valid && !b.valid){
        cout<<"None";
    }else if(a.gpa != b.gpa){
        if(a.gpa > b.gpa) cout<<a.id;
        else cout<<b.id;
    }
    else if(a.b != b.b){
        if(a.b < b.b) cout<<a.id;
        else cout<<b.id;
    }else if(a.c != b.c){
        if(a.c < b.c) cout<<a.id;
        else cout<<b.id;
    }else cout<<"Both";
}