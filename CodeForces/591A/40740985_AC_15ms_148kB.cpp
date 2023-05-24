#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    double l, p, q;
    cin >> l >> p >> q;
    cout << (p / (p + q))*l;
}
int main() {
    int tc=1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

}