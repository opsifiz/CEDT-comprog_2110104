#include <iostream>
using namespace std;
string dec2hex(int d) {
    if(d < 16){
        string res = "X";
        if(d<10) res[0] = d+'0';
        else res[0] = d+'A'-10;
        return res;
    }
    return dec2hex(d/16)+dec2hex(d%16);
}
int main() {
    int d;
    while (cin >> d) {
    cout << d << " -> " << dec2hex(d) << endl;
    }
    return 0;
}