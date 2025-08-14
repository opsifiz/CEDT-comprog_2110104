#include<iostream>
#include<cstring>
#define int long long
using namespace std;

int32_t main(){
    string target, t;
    getline(cin,target);
    getline(cin,t);
    int sz = t.size();
    int i = 0, j = -1;
    int cnt = 0;
    while(i<sz){
        while(i<sz && !islower(t[i])&&!isupper(t[i])) i++;
        j = i;
        string s;
        while(j<sz && (islower(t[j])||isupper(t[j]))) s += t[j++];
        cnt += target==s;
        i = j;
    }
    cout<<cnt;
}