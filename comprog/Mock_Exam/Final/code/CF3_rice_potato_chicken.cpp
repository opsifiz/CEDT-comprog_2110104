#include<bits/stdc++.h>
#define int long long
using namespace std;

deque<int> dq;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    int sum = 0;
    int dup = 0;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        dq.push_back(x);
        // sum += x;
    }
    while(q--){
        int mode, val;
        cin>>mode;
        if(mode == 1){
            cin>>val;
            // sum += val;
            dq.push_back(val);
        }else if(mode == 2){
            // sum -= dq.front()+dup;
            dq.pop_front();
        }else if(mode == 3){
            // sum -= dq.back()+dup;
            dq.pop_back();
        }else if(mode == 4){
            cin>>val;
            for(int i=0;i<dq.size();i++){
                dq[i] += val;
            }
            // dup += val;
            // int sz = dq.size();
            // sum += val*sz;
        }else if(mode == 5){
            cin>>val;
            deque<int> temp = dq; dq.clear();
            for(int i=0;i<temp.size();i++){
                if(temp[i] >= val){
                    dq.push_back(temp[i]);
                }/*else{
                    sum -= temp[i]+dup;
                }*/
            }
        }else if(mode == 6){
            cin>>val;
            int temp = 0;
            while(val--){
                temp += dq.back();
                dq.pop_back();
            }
            dq.push_front(temp);
        }
        // for(int i : dq) cout<<i<<' '; /*cout<<", sum = "<<sum;*/ cout<<'\n';
    }
    for(int i : dq) sum += i;
    cout<<dq.size()<<' '<<sum;
}
/*
5 6
1 2 3 4 5
1 6
4 2
5 5
3
6 2
2
*/