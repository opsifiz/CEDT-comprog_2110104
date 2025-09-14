#include<iostream>
#include<map>
#include<vector>
using namespace std;

map<string,vector<string>> g;

int main(){
    string temp;
    getline(cin,temp);
    int q = stoi(temp);
    while(q--){
        string s;
        int x = -1;
        getline(cin,s);
        int sz = s.size();
        for(int i=0;i<sz;i++){
            if(s[i] == ','){
                x = i;
                break;;
            }
        }
        g[s.substr(0,x)].push_back(s.substr(x+2));
    }
    string s;
    getline(cin,s);
    int i=0, sz=s.size();
    while(i<sz){
        string u;
        while(i<sz && s[i]==',') i++;
        while(i<sz && s[i] == ' ') i++;
        while(i<sz && s[i]!=',') u += s[i++];
        cout<<u<<" -> ";
        if(g.find(u) != g.end()){
            bool f = 1;
            for(string v : g[u]){
                if(!f) cout<<", ";
                else f=0;
                cout<<v;
            }
        }else{
            cout<<"Not found";
        }
        cout<<'\n';
    }
}