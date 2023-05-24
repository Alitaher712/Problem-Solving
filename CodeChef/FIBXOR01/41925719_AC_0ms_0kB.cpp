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
int  m;
int arr[10000];
int a, b, n;
int rec(int i) {
    if (i == 0) {
        return a;
    }
    if (i == 1) {
        return b;
    }
    return rec(i - 1) ^ rec(i - 2);
}
void WEKA() {
    long long ans[1000 + 1];
    cin >> a >> b >> n;
    if (n % 3 == 0) {
        cout << a << endl;
    }
    else if (n % 3 == 1) {
        cout << b << endl;
    }
    else {
        cout << (a ^ b) << endl;
    }
}
int main() {
    int t = 1;
     cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}