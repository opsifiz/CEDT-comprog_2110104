#include<iostream>
#include<set>
using namespace std;

set<int> s;

int main(){
    int target; cin>>target;
    int x, cnt = 0;
    while(cin>>x){
        cnt += (s.find(target-x) != s.end());
        s.insert(x);
    }
    cout<<cnt;
}