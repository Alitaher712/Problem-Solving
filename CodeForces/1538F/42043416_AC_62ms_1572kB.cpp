#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
const ll N = 2e5 + 5, INF = 1e18 + 5, mod = 1e9 + 7;

ll n, d, a[N], ans;

ll nC3(ll x) {
    if (x < 3)
        return 0;

    return x * (x - 1) * (x - 2) / 6;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    long long ans = r - l;
    while (l < r) {
        l /= 10;
        r /= 10;
        ans += r - l;
    }
    cout << ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}