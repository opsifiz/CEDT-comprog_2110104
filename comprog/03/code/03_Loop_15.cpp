#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    for(char &c : s){
        if(c == '(') c = '[';
        else if(c == ')') c = ']';
        else if(c == '[') c = '(';
        else if(c == ']') c = ')';
    }
    cout<<s;
}