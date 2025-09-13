#include<iostream>
#include<set>
#include<cstring>
using namespace std;

const int N = 2e5;

set<int> u, i, d, a[N+5];
int n = 0;

int main(){
    string s;
    while(getline(cin,s)){
        int j=0, sz=s.size();
        while(j<sz){
            int num = 0;
            while(j<sz && s[j]==' ') j++;
            while(j<sz && isdigit(s[j])){
                num = num*10+s[j]-'0';
                j++;
            }
            a[n].insert(num);
        }
        n++;
    }

    for(int j=0;j<n;j++){
        for(int x : a[j]){
            // cout<<x<<' ';
            u.insert(x);
        }
        cout<<'\n';
    }

    for(int x : a[0]){
        bool ii = 1, dd = 1;
        for(int j=1;j<n;j++){
            bool temp_ii = 0;
            for(int y : a[j]){
                if(x == y){
                    temp_ii = 1;
                    dd = 0;
                    break;
                }
            }
            ii &= temp_ii;
        }
        if(ii) i.insert(x);
        if(dd) d.insert(x);
    }

    cout<<"U: "; if(!u.size()) cout<<"empty set"; else{for(int x : u) cout<<x<<' ';} cout<<'\n';
    cout<<"I: "; if(!i.size()) cout<<"empty set"; else{for(int x : i) cout<<x<<' ';} cout<<'\n';
    cout<<"D: "; if(!d.size()) cout<<"empty set"; else{for(int x : d) cout<<x<<' ';} cout<<'\n';
}