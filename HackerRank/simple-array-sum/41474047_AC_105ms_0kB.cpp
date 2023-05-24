#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
    }
    cout <<sum<<endl;
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
