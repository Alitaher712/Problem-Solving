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
vector<long long>vec(200);
void rec(int i,long long cost) {
    int temp = vec[i];
      vec[i] = gcd(vec[i], i);
    rec(i + 1, cost + n - i + 1);
    vec[i] = temp;
    rec(i + 1, cost);
}
int primeFactors(int n)
{
    set<int> s;
    while (n % 2 == 0)
    {
        s.insert(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            s.insert(i);
            n = n / i;
        }
    }

    if (n > 2)
        s.insert(n);

    return (int)s.size();
}
vector<long long>vv[30000];
vector<long long>vvv(100000);
ll ncr(ll n)
{
    return n * (n - 1) / 2;
}
int cas = 0;
void solve() {
    cas++;
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout <<"Case "<<cas<<": "<< gcd(abs(x1 - x2), abs(y1 - y2))+1 << endl;;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
  //  sieve();
    cin >> t;
    while (t--)
        solve();
}