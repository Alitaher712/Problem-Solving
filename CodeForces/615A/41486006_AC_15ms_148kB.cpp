#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, m;
    cin >> n >> m;
    set<int>st;
    for (int i = 0; i < n; i++) {
        long long x,y;
        cin >> x;
        for (int i = 0; i < x; i++) {
            cin >> y;
            st.insert(y);
        }
    }
    if (st.size() == m) {
        cout << "YES\n";
    }
    else cout << "NO\n";
}

int main()
{
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}
