#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    long long c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == arr[n - i - 1]) {
            break;
        }
        else c++;
    }
    cout << max(0LL,n - (c * 2))<< endl;
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
