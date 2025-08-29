#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        // cout<<"MSG : "<<s<<'\n';
        int i = 0;
        int n = s.size();
        char t = s[n-1];
        while(i<n){
            if(s[i] == t){
                int j = i+1;
                while(j<n && s[j] != t){
                    cout<<s[j++];
                }
                i = j+1;
            }else{
                i++;
            }
        }
        cout<<'\n';
    }

}