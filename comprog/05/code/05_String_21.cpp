#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s; cin>>s;
    int i = 0, f=1;
    int n = s.size();
    while(i<n){
        string temp;
        temp += s[i++];
        while(1){
            if(isdigit(temp[0]) && isdigit(s[i])){
                temp += s[i];
                i++;
            }else if((isupper(temp[0])||islower(temp[0])) && islower(s[i])){
                temp += s[i];
                i++;
            }else{
                break;
            }
        }
        if(!f){
            cout<<", ";
        }else{
            f = 0;
        }
        cout<<temp;
    }
}