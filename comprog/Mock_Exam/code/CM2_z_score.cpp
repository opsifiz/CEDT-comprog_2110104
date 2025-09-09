#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    double z; cin>>z;
    vector<int> x;
    int val;
    while(cin>>val){
        if(val == -1) break;
        x.push_back(val);
    }
    double sd = 0, sum1=0, sum2=0;
    for(int xi : x){
        sum1 += xi;
        sum2 += xi*xi;
    }
    int n = x.size();
    double avg = sum1/n;
    sum2 /= n;
    sd = sqrt(sum2 - avg*avg);
    double score = z*sd+avg;
    cout<<fixed<<setprecision(5)<<score;
}