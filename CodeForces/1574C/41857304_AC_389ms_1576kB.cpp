#include <bits/stdc++.h>
#define ll long long
#define ld  long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, m;
ll a[N];
int main() {
    IO
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    cin >> m;
    while (m--) {
        ll x, y;
        cin >> x >> y;
        int id = lower_bound(a + 1, a + 1 + n, x) - a;
        ll ans = 4e18;
        if (id <= n)
            ans = max(0LL, y - (sum - a[id]));

        id--;
        if (id) {
            ans = min(ans, x - a[id] + max(0LL, y - (sum - a[id])));
        }
        cout << ans << "\n";
    }

}
