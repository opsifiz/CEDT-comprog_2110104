#include<bits/stdc++.h>
#define int long long
#define dd pair<pair<int,int>,pair<double,string>>
using namespace std;

const int N = 10;

bool cmp0(dd &a, dd &b){
    if(a.second.first == b.second.first){
        if(a.first.first == b.first.first){
            return a.second.second < b.second.second;
        }
        return a.first.first < b.first.first;
    }
    return a.second.first > b.second.first;
}

bool cmp1(dd &a, dd &b){
    if(a.second.first == b.second.first){
        if(a.first.second == b.first.second){
            return a.second.second < b.second.second;
        }
        return a.first.second > b.first.second;
    }
    return a.second.first> b.second.first;
}

bool cmp2(dd &a, dd &b){
    return a.second.second < b.second.second;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string id;
    double gpa;
    int hrs;
    int income;
    vector<dd> vec[3];
    while(cin>>id){
        if(id == "END") break;
        cin>>gpa>>hrs>>income;
        if(gpa >= 3.75 && income <= 300000){
            vec[0].push_back({{income,hrs},{gpa,id}});
        }else if(gpa >= 3.50 && hrs >= 100){
            vec[1].push_back({{income,hrs},{gpa,id}});
        }else{
            vec[2].push_back({{income,hrs},{gpa,id}});
        }
    }
    if(vec[0].size()){
        sort(vec[0].begin(),vec[0].end(),cmp0);
        cout<<"Qualified\n";
        for(auto &v : vec[0]){
            cout<<v.second.second<<'\n';
        }
    }
    if(vec[1].size()){
    sort(vec[1].begin(),vec[1].end(),cmp1);
        cout<<"Waiting List\n";
        for(auto &v : vec[1]){
            cout<<v.second.second<<'\n';
        }
    }
    if(vec[2].size()){
    sort(vec[2].begin(),vec[2].end(),cmp2);
        cout<<"Unqualified\n";
        for(auto &v : vec[2]){
            cout<<v.second.second<<'\n';
        }
    }

    
}