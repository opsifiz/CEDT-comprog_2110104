#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

struct record{
    string name;
    int people;
    int score;
    double temp;
};

bool cmp1(record &a, record &b){
    return a.temp > b.temp;
}

bool cmp2(record &a, record &b){
    if(a.people == b.people) return a.score > b.score;
    return a.people > b.people;
}

vector<record> d;

int main(){
    string te;
    int mp;
    int sum = 0, n = 0;
    double avg = 0;
    while(cin>>te){
        if(te == "END") break;
        cin>>mp;
        sum += mp;
        n++;
        record cur;
        cur.name = te;
        cur.people = 0;
        cur.score= mp;
        d.push_back(cur);
        // cout<<cur.name<<' '<<cur.score<<'\n';
    }
    avg = sum*1.0/100;
    int people = 0;
    // cout<<avg;
    for(auto &x : d){
        x.people = x.score/avg;
        x.temp = x.score*1.0/avg-x.people;
        people += x.people;
        // cout<<x.name<<' '<<x.people<<' '<<x.score<<'\n';
    }
    sort(d.begin(),d.end(),cmp1);
    // cout<<people<<'\n';
    for(auto &x : d){
        if(people < 100){
            x.people += 1;
            people++;
        }else{
            break;
        }
        // cout<<x.name<<' '<<x.people<<' '<<x.score<<'\n';
    }
    sort(d.begin(),d.end(),cmp2);
    for(auto &x : d){
        if(x.people == 0) break;
        cout<<x.name<<' '<<x.people<<' '<<x.score<<'\n';
    }
}