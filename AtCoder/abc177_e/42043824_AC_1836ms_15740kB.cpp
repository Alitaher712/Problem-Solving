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
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
void solve() {
    long long n;
    cin >> n;
    vector<long long>vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    long long gc =vec[0];
    for (int i = 1; i < n; i++) {
        gc = gcd(gc, vec[i]);
    }
    bool pairs = 1;
    map<long long, long long>mp;
    for (int i = 0; i < n; i++) {
        for (int j = 2; j * j <=vec[i]; j++) {
            if (vec[i] % j == 0) {
                if (mp[j]) {
                    pairs = 0;
                }
                mp[j]=1;
                while (vec[i] % j == 0)vec[i] /= j;
            }
        }
        if (vec[i] != 1) {
            if (mp[vec[i]]) {
                pairs = 0;
            }
            mp[vec[i]]=1;
        }
    }
    if (pairs) {
        cout << "pairwise coprime\n";
    }
    else if (!pairs && gc == 1) {
        cout << "setwise coprime\n";
    }
    else cout << "not coprime\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
  //  cin >> t;
    while (t--)
        solve();
}