#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int n,x,y,c=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (abs(x - y) >= 2) {
            c++;
        }
    }
    cout << c << '\n';
}
int main() {
    Ali
    int tc=1;
  //  cin >> tc;
    while (tc--) {
        solve();
    }

}