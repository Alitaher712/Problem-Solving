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
long long n;
int lis_ending_here(int arr[], int curr) {
    if (curr == 0)
        return 1;
    int ans = 1;
    for (int i = curr - 1; i >= 0; i--)
        if (arr[i] < arr[curr])
            ans = max(ans, 1 + lis_ending_here(arr, i));
            return ans;
}
int longest_increasing_subsequence(int arr[], int N) {
    int max_ans = 1;
    for (int i = 0; i < n; i++)
        max_ans = max(max_ans, lis_ending_here(arr, i));
    return max_ans;
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
long long su(int i) {
    long long sum = 1;
    while (i != 0) {
        if (i % 10 != 0) {
            sum *= i % 10;
        }
        n /= 10;
    }
    return sum;
}
int rec(int i) {
    if(i==0)
    return rec(i - 1) ^ rec(i - 2);
}
int a[1001][1001];
int c[100001];
void WEKA() {
    long long n, m, k;
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= k; i++) {
        int x = 1;
        int y = c[i];
        for (int x = 1; x <= n;) {
            if (a[x][y] == 1) {
                a[x][y] = 2;
                y++;
            }
            else if (a[x][y] == 3) {
                a[x][y] = 2;
                y--;
            }
            else
                x++;
        }
        cout << y << " ";
    }
    cout << endl;
}
int main() {
    int t = 1;
   //  cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}