#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;

map<string,string> mp;

void init(){
    mp["0"] = " ";
    mp[" "] = "0";
    string cur = "a";
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'2');
        mp[string(i,'2')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'3');
        mp[string(i,'3')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'4');
        mp[string(i,'4')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'5');
        mp[string(i,'5')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'6');
        mp[string(i,'6')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=4;i++){
        mp[cur] = string(i,'7');
        mp[string(i,'7')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=3;i++){
        mp[cur] = string(i,'8');
        mp[string(i,'8')] = cur;
        cur[0]++;
    }
    for(int i=1;i<=4;i++){
        mp[cur] = string(i,'9');
        mp[string(i,'9')] = cur;
        cur[0]++;
    }
    // for(auto x : mp){
    //     cout<<x.first<<' '<<x.second<<'\n';
    // }
    // cout<<'\n';
}

int main(){
    init();
    string s;
    while(getline(cin,s)){
        int i=0, sz=s.size();
        string mode = s.substr(0,3);
        string val = s.substr(4);
        // cout<<mode<<"/"<<val<<'\n';
        cout<<">>";
        if(mode == "T2K"){
            for(char c : val){
                if('A' <= c && c <= 'Z') c += -'A'+'a';
                string x;
                x += c;
                // cout<<"X = "<<x;
                cout<<' '<<mp[x];
            }
        }else{
            cout<<' ';
            vector<string> words;
            int i=0, sz=val.size();
            while(i<sz){
                while(i<sz&&val[i]==' ') i++;
                string num;
                while(i<sz&&isdigit(val[i])) num += val[i++];
                cout<<mp[num];
            }

        }
        cout<<'\n';
    }
}