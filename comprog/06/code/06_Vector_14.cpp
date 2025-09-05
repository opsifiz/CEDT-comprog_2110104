#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> temp;
    int x;
    while(cin>>x){
        temp.push_back(x);
    }
    sort(temp.begin(),temp.end());
    vector<int> v={temp[0]};
    for(int i=1;i<temp.size();i++){
        if(temp[i-1] != temp[i]){
            v.push_back(temp[i]);
        }
    }
    cout<<v.size()<<'\n';
    for(int i=0;i<min(10,(int)v.size());i++) cout<<v[i]<<' ';
}