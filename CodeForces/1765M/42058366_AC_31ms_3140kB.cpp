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
vector<int> v;
int vis[N] = {};
vector<int> isprime(N + 1, 1);
vector<int> primes;
void sieve()
{
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = 0;
            if (i % p == 0) {
                break;
            }
        }
    }
}
void solve() {
    long long n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << " " << n / 2 << endl;
    }
    else {
        long long d=n;
        for (int i = 3; i * i <= n; i++) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }
        long long a = n / d;
        long long b = a * (d-1);
        cout << a << " " << b << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
  //  sieve();
    cin >> t;
    while (t--)
        solve();
}