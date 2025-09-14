#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

map<string,double> mp, sell;
vector<string> res;
int mx = 0;
double sum = 0;

int main(){
    int n, m; cin>>n;
    for(int i=1;i<=n;i++){
        string name; double val;
        cin>>name>>val;
        mp[name] = val;
    }
    cin>>m;
    while(m--){
        string name; int val;
        cin>>name>>val;
        if(mp.find(name) != mp.end()){
            sell[name] += val*mp[name];
            if(sell[name] > mx){
                mx = sell[name];
                res = {name};
            }else if(sell[name] == mx){
                res.push_back(name);
            }
            sum += val*mp[name];
        }
    }
    if(res.size()){
        sort(res.begin(),res.end());
        cout<<"Total ice cream sales: "<<sum<<"\n";
        cout<<"Top sales:"; for(string x : res) cout<<' '<<x;
    }else{
        cout<<"No ice cream sales";
    }
}