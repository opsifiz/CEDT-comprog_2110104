#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000;

vector<pair<int,int>> vec;
int cnt = 0;

int n, m;

map<int,int> mp, res;
void sol(int i, int sum){
    if(i == n){
        if(sum == m){
            cnt++;
        }
        return;
    }
    if(sum > m) return;
    if(res[vec[i].first] < mp[vec[i].first]){
        sum += vec[i].first;
        res[vec[i].first] += 1;
        sol(i,sum);
        sum -= vec[i].first;
        res[vec[i].first] -= 1;
    }
    sol(i+1,sum);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a, b;
        cin>>a>>b;
        vec.push_back({a,b});
        mp[a] = b;
    }
    sol(0,0);
    cout<<cnt<<'\n';
}