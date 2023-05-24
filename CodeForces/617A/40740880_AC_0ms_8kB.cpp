#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    int x,y;
    cin >> x;
    if (x % 5 == 0) {
        cout << x / 5<<'\n';
    }
    else
    cout <<x/5+1 << '\n';
}
int main() {
    int tc=1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

}