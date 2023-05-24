#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;
#define el '\n'
using namespace std;
const ll N = 1e5 + 5, INF = 1e10, mod = 998244353;

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
void rec(int i,long long cost) {
    
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
//-----------------------------------------------Solve--------------------------------------------------------------------
void solve() {
    ll ans = 1; int n, x, cnt = 0; int arr[109] = { 0 };
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];
    x = find(arr, arr + n, 1) - arr;
    if (x == n)return cout << 0,void();
    for (int i = x; i < n; i++) {
        if (arr[i] == 0)cnt++;
        else ans *= cnt + 1, cnt = 0;
    }
    cout << ans;
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
ll n, q,p;
bool bs(int x)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - x * q <= 0)
            continue;
        ll now = (arr[i] - x * q);
        ans += now / (p-q) + ((now % (p-q)) != 0);
    }
    return(ans <= x);
}
int main()
{
    int t = 1;
    pre();
  //a  cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}