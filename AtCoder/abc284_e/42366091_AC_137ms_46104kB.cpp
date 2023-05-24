#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long
#define el '\n'
#define mbappe ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const ll N = 1e6 + 5, INF = 1e10, mod = 1000000007;
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
ll ncr(ll n)
{
    return n * (n - 1) / 2;
}
bool visited[N];
ll ans = 1;
vector<ll>anser;
vector<vector<ll>>adj(N);
void dfs(int node) {
    ans++;
    if (ans > 1e6) {
        return;
    }

    if (visited[node]) {
        return;
    }
    visited[node] = 1;
    //  cout << node << " ";
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    visited[node] = 0;
}
int dx[] = { 0, 0,-1, 1, 1,-1,-1, 1 };
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };
void bfs(int node) {
    queue<int>nexttovisit;
    nexttovisit.push(node);
    visited[node] = 1;
    ll lvl = 0;
    while (nexttovisit.size()) {
        int sz = nexttovisit.size();
        while (sz--) {
            int cur = nexttovisit.front();
            visited[cur] = 1;
            nexttovisit.pop();
            //  cout << cur << el;
            for (auto i : adj[cur]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    nexttovisit.push(i);
                }
            }
        }
        lvl++;
    }
    cout << lvl - 1 << el;
}
bool t = false;
pair<ll, ll>diameter(ll i, ll par = -1) {
    ll dim = 0;
    ll maxjigh[3] = { -1,-1,-1 };
    for (auto node : adj[i]) {
        if (node != par) {
            pair<ll, ll>p = diameter(node, i);
            dim = max(p.first, dim);
            maxjigh[0] = p.second + 1;
            sort(maxjigh, maxjigh + 3);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (maxjigh[i] == -1) {
            maxjigh[i] = 0;
        }
    }
    dim = max(dim, maxjigh[1] + maxjigh[2]);
    return make_pair(dim, maxjigh[2]);
}
//-----------------------------------------------Solve--------------------------------------------------------------------
void solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << min(ans-1,(ll) 1e6) << el;
    //  cout << level[4] << el;
}

int main()
{
    int t = 1;
    //pre();
    mbappe;
    //  sieve();
  //   cin >> t;
    while (t--) {
        solve();

    }
    return 0;
}