#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
vector<long long>vec(20);
long long n, l, r, x;
long long ans = 0;
void rec(int i,long long sum,long long mx,long long mn,long long cnt) {
    if (i == n) {
        if (sum >= l && sum <= r && cnt >= 2 && mx - mn >= x) {
            ans++;
        }
        return;
    }
        rec(i + 1, sum + vec[i], max(mx, vec[i]), min(mn, vec[i]), cnt + 1);
        rec(i + 1, sum,mx,mn, cnt);
}
void WEKA() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    rec(0, 0, 0, INT_MAX, 0);
    cout << ans << endl;

}
int main() {
    int t = 1;
   //  cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}