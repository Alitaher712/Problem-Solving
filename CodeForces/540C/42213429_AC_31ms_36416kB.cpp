#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long
#define el '\n'
#define mbappe ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const ll N = 1e6+5, INF = 1e10,mod= 1000000007;
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
void dfs(int node,vector<vector<int>>adj) {
    if (visited[node]) {
        return;
    }
    visited[node] = 1;
//    cout << node << el;
    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, adj);
        }
    }
}
int dx[] = { 0, 0,-1, 1, 1,-1,-1, 1 };
int dy[] = { 1,-1, 0, 0, 1,-1, 1,-1 };
void bfs(int node, vector<vector<int>>adj) {
    queue<int>nexttovisit;
    nexttovisit.push(node);
    visited[node] = 1;
    ll lvl = 0;
    while(nexttovisit.size()){
        int sz = nexttovisit.size();
        while (sz--) {
            int cur = nexttovisit.front();
            visited[cur] = 1;
            nexttovisit.pop();
             cout << cur << el;
            for (auto i : adj[cur]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    nexttovisit.push(i);
                }
            }
        }
        lvl++;
    }
}
bool t = false;
void check(int i, int j,int r,int c,int n,int m,char arr[501][501]) {
    for(int k=0;k<4;k++){
        int rr = i + dx[k];
        int cc = j + dy[k];
        if (rr < 0 || rr >= n)continue;
        if (cc < 0 || cc >= m)continue;
        if (rr == r && cc == c&&arr[rr][cc]=='X') {
            t=true;
            return;
        }
        if (arr[rr][cc] == '.') {
            arr[rr][cc] = 'X';
            check(rr, cc, r, c, n, m, arr);
        }
    }
   // return false;

}
//-----------------------------------------------Solve--------------------------------------------------------------------
void solve() {
    ll n, m;
    cin >> n >> m;
    char arr[501][501];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--; r2--; c1--; c2--;
    check(r1, c1, r2, c2, n, m, arr);
    if(t) {
        cout << "YES\n";
    }
    else cout << "NO\n";
    
    
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