#include <iostream>
using namespace std;
const int R = 7, C = 7;
void floodfill(int x[][C], int r, int c, int e) {
    if(x[r][c]) return;
    if(r < 0 || c < 0 || r >= R || c >= C) return;
    x[r][c] = e;
    floodfill(x,r+1,c,e);
    floodfill(x,r-1,c,e);
    floodfill(x,r,c+1,e);
    floodfill(x,r,c-1,e);
}
int main() {
    int x[][C] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}};
    for (int r=0; r<R; ++r)
        for (int c=0; c<C; ++c)
        cin >> x[r][c];
    int row, col, e;
    cin >> row >> col >> e;
    floodfill(x, row, col, e);
    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c)
            cout << x[r][c] << ' ';
        cout << endl;
    }
}