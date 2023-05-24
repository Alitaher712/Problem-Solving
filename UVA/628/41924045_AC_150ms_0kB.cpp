#include <bits/stdc++.h>
using namespace std;
long long factorial(long long n)
{
    if (n == 0)
        return 1;
    long long i = n, fact = 1;
    while (n / i != n) {
        fact = fact * i;
        i--;
    }
    return fact;
}
map<long long, int>mp;
void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        mp[2] = 1;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            mp[i] = 1;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n] = 1;
}
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to calculate all common divisors
// of two given numbers
// a, b --> input integer numbers
int commDiv(int a, int b)
{
    // find gcd of a, b
    int n = gcd(a, b);

    // Count divisors of n.
    int result = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        // if 'i' is factor of n
        if (n % i == 0) {
            // check if divisors are equal
            if (n / i == i)
                result += 1;
            else
                result += 2;
        }
    }
    return result;
}
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
string dect[10000];
int n, m;
string law;
int len;
int id;
string digits[] = {"0","1","2","3","4","5","6","7","8","9"};
void rec(int i,string s) {
    if (i == law.size()) {
        cout << s << endl;
        return;
    }
    if (law[i] == '#') {
        for (int j = 0; j < n;j++) {
             rec(i + 1, s + dect[j]);
        }
    }
    else {
        for (int j = 0; j <= 9; j++) {
             rec(i + 1, s + digits[j]);
        }
    }
}
void WEKA() {
    while ( cin >> n) {
        cout << "--\n";
        for (int i = 0; i < n; i++) {
            cin >> dect[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> law;
            rec(0,  "");
        }
    }
}
int main() {
    int t = 1;
  //    cin  >> t;
    while (t--) {
         WEKA();
    }
    return 0;
}