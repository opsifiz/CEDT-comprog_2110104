#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

map<string,int> mp;

void init(){
    mp["soon"] = 0;
    mp["neung"] = 1;
    mp["song"] = 2;
    mp["sam"] = 3;
    mp["si"] = 4;
    mp["ha"] = 5;
    mp["hok"] = 6;
    mp["chet"] = 7;
    mp["paet"] = 8;
    mp["kao"] = 9;
    mp["sip"] = 10;
    mp["et"] = 1;
    mp["yi"] = 2;
    mp["roi"] = 100;
    mp["phan"] = 1000;
    mp["muen"] = 10000;
    mp["saen"] = 100000;
    mp["lan"] = 1000000;
}

int main(){
    init();
    string s;
    while(getline(cin,s)){
        int res = 0;
        if(s == "soon"){
            cout<<"0\n";
            continue;
        }else if(s == "sip"){
            cout<<"10\n";
            continue;
        }else if(s == "q") break;
        vector<string> words;
        int i=0, n=s.size();
        while(i<n){
            string word;
            while(i<n && s[i]==' ') i++;
            while(i<n && s[i]!=' '){
                word += s[i];
                i++;
            }
            words.push_back(word);
        }
        // for(auto x : words){
        //     cout<<x<<' ';
        // }
        i = 0;
        n = words.size();
        int num = 0;
        while(i<n){
            int j = i;
            int cur = mp[words[j]];
            j++;
            if(cur < 10){
                if(j<n && mp[words[j]] >= 10){
                    num += cur*mp[words[j]];
                    j++;
                }else{
                    num += cur;
                }
            }else if(cur == 10 && j<n){
                num += cur+mp[words[j]];
                j++;
            }else if(cur == 10 && j==n){
                num += cur;
            }else{
                cout<<cur<<' '<<j<<'\n';
            }
            i = j;
        }
        cout<<num<<'\n';
    }
}
//9 999 999