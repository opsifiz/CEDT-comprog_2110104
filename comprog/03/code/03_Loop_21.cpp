#include<iostream>
using namespace std;

const int N = 2e5;

int chk(string s){
    int n = s.size();
    if(n < 8) return 0;
    int A=0, a=0, _a=0, d=0;
    for(char c : s){
        if(isupper(c)) A = 1;
        else if(islower(c)) a = 1;
        else if(isdigit(c)) d = 1;
        else _a = 1;
    }
    if(A&&a&&_a&&d&&n>=12) return 2;
    else if(A&&a&&d) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    while(cin>>s){
        int m = chk(s);
        if(m == 2) cout<<">> strong\n";
        else if(m == 1) cout<<">> weak\n";
        else cout<<">> invalid\n";
    }
}