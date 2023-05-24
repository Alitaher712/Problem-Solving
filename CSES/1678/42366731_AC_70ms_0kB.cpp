#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
int n, m, visited[MAX_N], par[MAX_N];
vi adj[MAX_N];

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            par[v] = u;
            dfs(v);
        }
        else if (visited[v] == 1) {
            vi ans = { v };
            for (int i = u; i != par[v]; i = par[i]) ans.push_back(i);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (int x : ans) cout << x << " ";
            cout << "\n";
            exit(0);
        }
    }
    visited[u] = 2;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(i);
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}