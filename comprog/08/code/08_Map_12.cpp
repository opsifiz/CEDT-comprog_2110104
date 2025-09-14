#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

map<string,string> mp;

int main(){
    int n, m;
    string num; getline(cin,num);
    n = stoi(num);
    while(n--){
        // cout<<"hm\n";
        string s; getline(cin,s);
        string a, b;
        vector<string> temp;
        int i = 0, len = s.size();
        while(i<len){
            while(i<len && s[i]==' ') i++;
            string t;
            while(i<len && s[i]!=' '){
                t += s[i];
                i++;
            }
            temp.push_back(t);
        }
        a = temp[0];
        int sz = temp.size();
        for(int i=1;i<sz-1;i++){
            a += ' '+temp[i];
        }
        b = temp[sz-1];
        mp[b] = a;
        mp[a] = b;
    }
    getline(cin,num);
    m = stoi(num);
    while(m--){
        string b;
        getline(cin,b);
        cout<<b<<" --> ";
        if(mp.find(b) == mp.end()) cout<<"Not found";
        else cout<<mp[b];
        cout<<'\n';
    }
}