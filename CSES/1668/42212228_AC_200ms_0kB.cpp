#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+3;
vector<bool> visited(N, false);
vector<int> col(N, 0);
vector<int> adj[N];
int n, m;
 
bool dfs(int u, int c, int par) {
	visited[u] = true;
	col[u] = c;
	for(auto i : adj[u]) {
		if(i == par)
			continue;
		if(col[i] == 0) {
			if(!dfs(i, c xor 3, u)) {
				return false;
			}
		}
		if(col[i] == col[u])
			return false;
	}
	return true;
}
 
bool color_all() {
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			if(!dfs(i, 1, -1)) // vertex, color, parent
				return false;
		}
	}
	return true;
}
 
int main() {
	cin >> n;
	cin >> m;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool ans = color_all();
	if(ans) {
		for(int i = 1; i <= n; i++) {
			cout << col[i] << " ";
		}
	}
	else {
		puts("IMPOSSIBLE");
	}
	return 0;
 }