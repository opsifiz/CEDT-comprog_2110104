#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int main(){
    string s; cin>>s;
    string sub = s.substr(0,2);
    if(s.size() == 10 && (sub=="06" || sub=="08" || sub=="09")){
        cout<<"Mobile number";
    }else{
        cout<<"Not a mobile number";
    }
    
}