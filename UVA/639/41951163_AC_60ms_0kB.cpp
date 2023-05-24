#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)

const int dx[] = { 0, 1, -1, 0 };
const int dy[] = { -1, 0, 0, 1 };
int n, res;
char arr[10][10];
bool mark[10][10];
bool inside(int x, int y) {
    return (0 <= x && x < n && 0 <= y && y < n);
}
bool canPlace(int x, int y) {
    if (arr[x][y] == 'X') return false;
    for (int i = 0; i < 4;i++) {
        int xx = x, yy = y;
        while (inside(xx, yy)) {
            if (arr[xx][yy] == 'X') break;
            if (mark[xx][yy]) return false;
            xx += dx[i]; yy += dy[i];
        }
    }
    return true;
}

void backTrack(int x, int y, int tmpRes) {
    if (y == n)
    {
        x++;
        y = 0;
    }

    res = max(res, tmpRes);
    if (x >= n) return;
    fr(i, x, n - 1) {
        fr(j, y, n - 1) {
            backTrack(i, j + 1, tmpRes);
            if (canPlace(i, j)) {
                mark[i][j] = true;
                backTrack(i, j + 1, tmpRes + 1);
                mark[i][j] = false;
            }
        }
        y = 0;
    }
}
int main() {
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        memset(mark, false, sizeof(mark));
        res = 0;
        backTrack(0, 0, 0);
        cout << res << endl;
    }
    return 0;
}