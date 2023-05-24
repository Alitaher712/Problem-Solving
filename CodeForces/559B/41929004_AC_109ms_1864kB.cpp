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
string rec(string s) {
    if (s.size() % 2 == 1) return s;
    string a = "", b = "";
    int l = s.size();
    for (int i = 0; i < l / 2; i++) a += s[i];
    for (int i = l / 2; i < l; i++) b += s[i];
    a = rec(a);
    b = rec(b);
    if (a > b) swap(a, b);
    return a + b;
}
void WEKA() {
    cin >> s1 >> s2;
    s1 = rec(s1);
    s2 = rec(s2);
    if (s1 == s2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
int main() {
    int t = 1;
   //  cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}