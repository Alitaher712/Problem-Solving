#include<bits/stdc++.h>
using namespace std;

#define int      long long
#define all(xs)   xs.begin(), xs.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

vector<int> adj[500005];
vector<int> ans(500005);
void dfs(int i , int par) {
    ans[i] = par;

    for (auto j : adj[i]) {
        if (j != par) {
            dfs(j , i);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n , r1 , r2;
    cin >> n >> r1 >> r2;
    int id = 1;
    for (int i = 0; i < n - 1; i++) {
        if (id == r1) {
            id++;
        }
        int x;
        cin >> x;
        adj[x].push_back(id);
        adj[id].push_back(x);
        id++;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto j : adj[i]) {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    dfs(r2 , 0);
    for (int i = 1; i <= n; i++) {
        if (i == r2) {
            continue;
        }
        cout << ans[i] << " ";
    }
}