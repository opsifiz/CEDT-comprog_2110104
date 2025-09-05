#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> st, val, sz;

int main(){
    int x, mx=-1;
    vector<int> v;
    while(cin>>x) v.push_back(x);
    int i = 0, n = v.size();
    while(i<n){
        int j = i;
        int cnt = 0;
        while(j<n && v[i]==v[j]){
            j++;
            cnt++;
        }
        val.push_back(v[i]);
        st.push_back(i);
        sz.push_back(cnt);
        mx = max(mx,cnt);
        i = j;
    }
    // cout<<mx<<'\n';
    vector<string> res;
    for(int i=0;i<val.size();i++){
        if(sz[i] != mx) continue;
        string s = to_string(val[i])+" --> x[ "+to_string(st[i])+" : "+to_string(st[i]+sz[i])+" ]";
        res.push_back(s);
    }
    sort(res.begin(), res.end());
    for(string s : res){
        cout<<s<<'\n';
    }
}