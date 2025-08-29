#include<iostream>
#include<cstring>
using namespace std;

int main(){
    /*
    1
    1*10
    1*10*10
    1*10*10*26
    1*10*10*26*26
    */
   string s; int n;
   cin>>s>>n;

    cin>>n;

    int A = n/(10*10*10*26*26);
    n %= (10*10*10*26*26);
    
    int B = n/(10*10*10*26);
    n %= (10*10*10*26);
    
    int C = n/(10*10*10);
    n %= (10*10*10);
    
    int D = n/(10*10);
    n %= (10*10);
    
    int E = n/10;
    n %= 10;
    
    // cout<<"N = "<<n<<'\n';
    // cout<<A<<' '<<B<<' '<<C<<"-"<<D<<' '<<E<<' '<<n<<'\n';

    string res(7,'-');
    int temp = 0;
    int a[] = {A,B,C,D,E,n};

    for(int i=6;i>=4;i--){
        res[i] = s[i]-'0'+a[i-1]+temp;
        if(res[i] > 9) temp = 1, res[i] -= 10;
        else temp = 0;
        res[i] += '0';
    }

    for(int i=2;i>=1;i--){
        res[i] = s[i]-'A'+1+a[i]+temp;
        if(res[i] > 26) temp = 1, res[i] -= 26;
        else temp = 0;
        res[i] += 'A'-1;
    }
    
    res[0] = s[0]+a[0]+temp;
    cout<<res;
}