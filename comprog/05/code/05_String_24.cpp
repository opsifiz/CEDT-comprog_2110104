#include<iostream>
#include<cstring>
#include<set>
using namespace std;

const int N = 2e5;

string a[N+5];
int n = 0;

set<char> vowel{'a','e','i','o','u'};

pair<string,string> cal(string s){
    string te, mp;
    int i = 0, sz = s.size();
    while(i<sz){
        if(vowel.find(s[i]) != vowel.end()){
            while(i<sz){
                mp += s[i];
                i++;
            }
            break;
        }
        te += s[i];
        i++;
    }
    return {te,mp};
}

int main(){
    string s, t;
    while(cin>>s){
        a[n++] = s;
    }
    pair<string,string> x, y;
    x = cal(a[0]);
    y = cal(a[n-1]);
    a[0] = x.first+y.second;
    a[n-1] = y.first+x.second;
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
}