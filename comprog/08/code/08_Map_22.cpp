#include<iostream>
#include<map>
using namespace std;

map<string,double> mp;

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        string s; double x;
        cin>>s>>x;
        mp[s] = x;
    }
    long long cur; cin>>cur;
    string prev, curr;
    cin>>prev;
    cout<<cur<<' '<<prev;
    mp["THB"] = 1;
    while(cin>>curr){
        cur = (long long)(cur*mp[prev]/mp[curr]);
        // if(curr == "THB") cur *= mp[prev];
        // else if(prev == "THB") cur /= mp[curr];
        // else if(curr != prev){
        //     cur = (long long)(cur*mp[prev]/mp[curr]);
        // }
        cout<<" -> "<<cur<<' '<<curr;
        prev = curr;
    }
}