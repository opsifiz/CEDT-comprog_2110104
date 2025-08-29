#include<iostream>
#include<cstring>
#include<map>
using namespace std;

string key;

int main(){
    getline(cin,key);
    int sz = key.size();
    char mode;
    string txt;
    // cout<<"key size = "<<sz<<'\n';
    for(char &c : key){
        if('A' <= c && c <= 'Z') c -= 'A'-'a';
    }
    // cout<<"Key = \""<<key<<"\"\n";
    while(getline(cin,txt)){
        string s;
        mode = txt[0];
        txt = txt.substr(2);
        // cout<<"txt = "<<txt<<'\n';
        if(mode == 'E'){
            int idx = 0;
            int n = 4;
            for(char c : txt){
                int code;
                if(c == '-') code = 10;
                else if(c == ',') code = 11;
                else code = c-'0';
                // cout<<"code = "<<code<<'\n';
                for(int i=3;i>=0;i--){
                    while(!('a' <= key[idx] && key[idx] <= 'z') && !('A' <= key[idx] && key[idx] <= 'Z')){
                        s += key[idx];
                        idx = (idx+1)%sz;
                    }
                    if(code&(1<<i)) s += key[idx];
                    else s += toupper(key[idx]);
                    idx = (idx+1)%sz;
                }
            }
        }else{
            string temp;
            for(char c : txt){
                if(islower(c) || isupper(c)) temp += c;
            }
            for(int i=0;i<temp.size();i+=4){
                int bit = 0;
                for(int j=0;j<4;j++){
                    bit = 2*bit+('a'<=temp[i+j]&&temp[i+j]<='z');
                    // cout<<bit<<' ';
                }
                // cout<<'\n';
                // cout<<"bit = "<<bit<<'\n';
                char res;
                if(bit == 10) res = '-';
                else if(bit == 11) res = ',';
                else res = bit+'0';
                s += res;
            }
        }
        cout<<s<<'\n';
    }
}