#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
vector<long long>vec(20);
long long n, l, r, x;
long long ans = 0;
string s1, s2;
int c = -1;
void rec(long long n,long long m,long long cnt) {
    if (n > m) {
        return;
    }
    if (n == m) {
        c = cnt;
        return;
    }
    rec(n * 2, m,cnt+1);
    rec(n * 3, m,cnt+1);
}
void WEKA() {
    long long n, m;
    cin >> n >> m;
    rec(n, m, 0);
    cout << c << endl;
}
int main() {
    int t = 1;
   //  cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}