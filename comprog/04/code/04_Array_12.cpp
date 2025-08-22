#include<iostream>
using namespace std;

const int N = 2e5;

string names[] = {
    "Robert",
    "William",
    "James",
    "John",
    "Margaret",
    "Edward",
    "Sarah",
    "Andrew",
    "Anthony",
    "Deborah"
};

string nicknames[] = {
    "Dick",
    "Bill",
    "Jim",
    "Jack",
    "Peggy",
    "Ed",
    "Sally",
    "Andy",
    "Tony",
    "Debbie"
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    cin>>tc;
    while(tc--){
        string s; cin>>s;
        bool f = 0;
        for(int i=0;i<10;i++){
            if(names[i]==s){ f=1; cout<<nicknames[i]<<'\n';}
            else if(nicknames[i] == s){ f =1; cout<<names[i]<<'\n';}
        }
        if(!f) cout<<"Not found\n";
    }
}