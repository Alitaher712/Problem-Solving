#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long
#define el '\n'
#define mbappe ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const ll N = 1e6+5, INF = 1e10,mod= 998244353;
int fact[N], inv[N];
int fp(int b, int p)
{
    if (b == 1 || p == 0)
        return 1;
    int hp = fp(b, p / 2);
    int ans = (1LL * hp * hp) % mod;
    if (p % 2)
        ans = (1LL * ans * b) % mod;
    return ans;
}
ll mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
void pre()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll nCr(int n, int r)
{
    return ((1LL * fact[n] * inv[n - r]) % mod * inv[r]) % mod;
}
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
ll lcm(ll a, ll b) {
    ll g = gcd(a, b);
    return (a * b / g);
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
void rec(int i, long long cost) {

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
ll len(ll x)
{
    int cnt = 0;
    ll xx = x;
    while (xx)
    {
        xx /= 10;
        cnt++;
    }
    return cnt;
}
vector<ll>arr(2000001);
ll n, q, p;
bool bs(int x)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - x * q <= 0)
            continue;
        ll now = (arr[i] - x * q);
        ans += now / (p - q) + ((now % (p - q)) != 0);
    }
    return(ans <= x);
}
ll ncr(ll n)
{
    return n * (n - 1) / 2;
}
int cas = 0;
ll mp[N];
//-----------------------------------------------Solve--------------------------------------------------------------------
bool check(ll n) {
    set<char>st;
    while (n != 0) {
        st.insert(n % 10);
        n /= 10;
    }
    return (st.size() == 1);
}
vector<int> ma(10000001, 0);
vector<int> x(10000010, 0);
void solve() {
    ll n;
    cin >> n;
    if (x[n] != 0) {
        cout << x[n] << el;
    }
    else cout << -1 << el;
}

int main()
{
    int t = 1;
    //pre();
    mbappe;
    const int N = 1e7 + 10;
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i) ma[j] += i;

    for (int i = 1; i < N; i++)
        if (ma[i] < N && x[ma[i]] == 0) x[ma[i]] = i;
  //  sieve();
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}