#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, cnt=1;
    set<int> s;
    while(cin>>x){
        if(s.find(x) != s.end()){
            cout<<cnt;
            return 0;
        }else{
            s.insert(x);
            cnt++;
        }
    }
    cout<<-1;
}