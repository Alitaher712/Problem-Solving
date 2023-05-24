#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    double x,y;
    cin >> x>>y;
    cout <<((x-y)/3) +y << '\n';
}
int main() {
    int tc=1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

}