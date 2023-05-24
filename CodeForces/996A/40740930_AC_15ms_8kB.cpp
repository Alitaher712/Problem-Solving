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
    long long s1 = x / 100;
    long long r1 = x % 100;
    long long s2 = r1 / 20;
    r1 = r1 % 20;
    long long s3 = r1 / 10;
    r1 %= 10;
    long long s4 = r1 / 5;
    r1 %= 5;
    long long s5 = r1 / 1;
    cout << s1 + s2 + s3 + s4 + s5 << '\n';
}
int main() {
    int tc=1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

}