#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> s = {
        "01",
        "02",
        "20",
        "21",
        "22",
        "23",
        "24",
        "25",
        "26",
        "27",
        "28",
        "29",
        "30",
        "31",
        "32",
        "33",
        "34",
        "35",
        "36",
        "37",
        "38",
        "39",
        "40",
        "51",
        "53",
        "55",
        "58"
    };
    string t; cin>>t;
    if(s.find(t) != s.end()){
        cout<<"OK";
    }else{
        cout<<"Error";
    }
}