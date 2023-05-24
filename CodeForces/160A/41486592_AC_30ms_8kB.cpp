#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int* arr = new int[n];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    sum /= 2;
    long long sum2 = 0;
    long long c = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum2 += arr[i];
        c++;
        if (sum2 > sum) {
            break;
        }
    }
    cout << c << endl;
 
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
