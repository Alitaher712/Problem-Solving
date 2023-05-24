#include <bits/stdc++.h>
using namespace std;
int arr[10000];
int rec(const int l, const int r, const int h)
{
    if (l == r) {
        return 1;
    }
    int mn = 1e18;
    for (int i = l; i <= r; i++) {
        mn = min(arr[i] - h, mn);
    }
    int ans = mn;
    int s = l;
    while (s <= r)
    {
        while (s <= r && arr[s] - h == mn) {
            s++;
        }
        if (s <= r)
        {
            int e = s;
            while (e <= r && arr[e] - h > mn)
                e++;
            ans += rec(s, e - 1, h + mn);
            s = e;
        }
    }
    return min(ans, r - l + 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << rec(0, n - 1, 0);
}
