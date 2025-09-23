#include <iostream>
#include <map>
using namespace std;
int F(int n) { // Fibonacci number
    if(n < 2) return n;
    if(n&1) return F((n+1)/2)*F((n+1)/2)+F((n+1)/2-1)*F((n+1)/2-1);
    return (2*F(n/2-1)+F(n/2))*F(n/2);
}
int M(int n) { // Motzkin number
    if(n < 2) return 1;
    int sum = M(n-1);
    for(int i=0;i<=n-2;i++){
        sum += M(i)*M(n-2-i);
    }
    return sum;
}
int S(int n) { // Schröder–Hipparchus Number
    if(n < 3) return 1;
    return ((6*n-9)*S(n-1)-(n-3)*S(n-2))/n;

}
int D(int n) { // Derangement
    if(n == 0) return 1;
    return n*D(n-1)+(n&1?-1:1);
}
int main() {
    map<string, int(*)(int)> func = {{"F",F}, {"M",M}, {"S",S}, {"D",D}};
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
        }
    return 0;
}