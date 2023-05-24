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
int n;
long long sum = 0;
string num;
void rec(string s) {
    if (s.size() == n - 1) {
        string f="";
        for (int i = 0; i <s.size(); i++) {
            f += num[i];
            if (s[i] == '+') {
                f += s[i];
            }
        }
         f += num[n - 1];
         string temp;
        for (int i = 0; i < f.size(); i++) {
            if (f[i] >= '0' && f[i] <= '9') {
                temp += f[i];
            }
            if (f[i] == '+') {
                sum += stoll(temp);
                temp.clear();
            }
        }
        sum += stoll(temp);
        return;
        
    }
    rec(s+'+');
    rec(s+'%');
}
void WEKA() {
    cin >> num;
    n = num.size();
    rec("");
    cout << sum << endl;
}
int main() {
    int t = 1;
   //   cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}