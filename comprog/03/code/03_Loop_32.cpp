#include<bits/stdc++.h>
using namespace std;

bool valid(string s, int n){
    string tail="YGNBPK";
    if(n == 1) return s=="R";
    if(s[0] != 'R') return 0;
    int last = n-1;
    while(last>=0 && s[last]!='R') last--;
    if(last&1) return 0;
    int j = last+2;
    int sz = n-j;
    if(sz > 6){
    //     // cout<<j<<' '<<sz<<'\n';
        return 0;
    }
    for(int i=j;i<n;i++){
        if(tail[i-j] != s[i]){
            // cout<<"j = "<<j<<'\n';
            return 0;
        }
    }
    for(int i=0;i<=last;i+=2){
        if(s[i] == 'R' && s[i+1] == 'R') return 0;
        if(s[i] != 'R') return 0;
    }
    return 1;
}

void mains(){
    string t, s;
    getline(cin,t);
    // cout<<t<<' ';
    for(char c : t){
        if(c != ' '){
            s += c;
        }
    }
    int n = s.size();
    if(valid(s,n)){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='R' && s[i+1]=='R'){
                cout<<"WRONG_INPUT\n";
                return;
            }
            sum += s[i]=='R'?1:s[i]=='Y'?2:s[i]=='G'?3:s[i]=='N'?4:s[i]=='B'?5:s[i]=='P'?6:s[i]=='K'?7:0;
        }
        cout<<sum<<'\n';
    }else{
        cout<<"WRONG_INPUT\n";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    string temp;
    getline(cin,temp);
    tc = stoi(temp);
    while(tc--) mains();
}
/*
5
K R
R R Y
R B P G
R B R K Y B
R B Y G N B P K Y
*/