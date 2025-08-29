#include<iostream>
#include<cstring>
using namespace std;

string add(string a, string b){
    int n = a.size(), m = b.size();
    if(n < m){
        swap(n,m);
        swap(a,b);
    }
    while(b.size() < n) b = '0'+b;
    string res = string(n,'0');
    // cout<<a<<' '<<b<<' '<<res<<'\n';
    int temp = 0;
    for(int i=n-1;i>=0;i--){
        int cur = a[i]-'0'+b[i]-'0'+temp;
        temp = 0;
        if(cur > 9){
            temp = 1;
            cur -= 10;
        }
        // cout<<cur<<' ';
        res[i] = cur+'0';
    }
    // cout<<res<<'\n';
    if(temp){
        res = '1'+res;
    }
    return res;
}

int main(){
    string s = "0", t;
    while(cin>>t){
        if(t == "END") break;
        s = add(s,t);
    }
    cout<<s;
}