#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;

struct d{
    string name;
    int m;
    vector<int> lists;
    int missing = inf;
};

const int N = 100;

int x, n;

int mn = inf;

d a[N+5];


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        int sum = 0;
        cin>>a[i].name>>a[i].m;
        for(int j=1;j<=a[i].m;j++){
            int temp; cin>>temp;
            a[i].lists.push_back(temp);
            sum += temp;
            if(sum <= x){
                a[i].missing = a[i].m-j;
            }
        }
        if(a[i].missing < a[i].m){
            mn = min(mn,a[i].missing);
        }
    }
    if(mn == inf){
        cout<<"FIND SOMETHING FREE";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i].missing == mn){
            cout<<a[i].name<<'\n';
        }
    }
}