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
    cin >> n >> d;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = INF;
    for (int i = 0; i < n; i++) {//1 2 3 4
        int start = i;
        int end = upper_bound(a, a + n + 1, a[i] + d) - a - 1;
        ans += nC3(end - start + 1);
        ans -= nC3(end - start);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin >> t;
    while (t--)
        solve();
}