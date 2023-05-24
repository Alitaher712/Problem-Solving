#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int* arr = new int[n];
    long long f[2] = {};
    long long x = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < f[arr[i] & 1])
            x = 0;
        f[arr[i] & 1] = arr[i];
    }
    if (x)cout << "YES\n";
    else cout << "NO\n";
 
}

int main()
{
    int t = 1;
   cin >> t;
    while (t--) {
        solve();
    }
    return 0;

}
