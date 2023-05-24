#include <iostream>
using namespace std;

int f(int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 10 != 0)
        {
            ans *= (n % 10);
        }
        n /= 10;
    }
    return ans;
}

int g(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return g(f(n));
    }
}
const int N = 1e6 + 7;
int ans[N][11];
int main()
{
    for (int k = 1; k <= 9; k++)
    {
        int s = 0;
        for (int i = 1; i < N; i++)
        {
            s += (g(i) == k);
            ans[i][k] = s;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << ans[r][k] - ans[l - 1][k] << endl;
    }
}
