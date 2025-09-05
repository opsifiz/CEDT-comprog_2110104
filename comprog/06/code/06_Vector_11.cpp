#include<iostream>
#include<vector>
using namespace std;

vector<int> a[2];
int n, m;
int cur = 1, pre = 0;

int main(){
    int temp; cin>>temp;
    while(cin>>temp){
        if(temp == -1) break;
        a[cur].push_back(temp);
        cur ^= 1;
    }
    n = a[0].size();
    m = a[1].size();
    bool f = 1;
    cout<<"[";
    for(int i=n-1;i>=0;i--){
        if(!f) cout<<", ";
        else f = 0;
        cout<<a[0][i];
    }
    for(int i=0;i<m;i++){
        if(!f) cout<<", ";
        else f = 0;
        cout<<a[1][i];
    }
    cout<<"]";
}