#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define YES cout << "YES" <<endl;
#define Yes cout << "Yes" <<endl;
#define yes cout << "yes" <<endl;
#define NO cout << "NO" <<endl;
#define No cout << "No" <<endl;
#define no cout << "no" <<endl;
#define all(x) x.begin(), x.end()
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define ld long double
#define OO 1e18
#define UOO 18446744073709551615
#define INF 0x3f3f3f3f
#define fast_in_out ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define forn for (ll i =0; i<n; i++)
#define forn1 for (ll i =1; i<=n; i++)
#define prq priority_queue<ll>
#define vint vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vchar vector<char>
#define vstring vector<string>
#define el "\n"
#define wide5 setw(5) << setiosflags(ios::right)
#define popCnt(x) (__builtin_popcountll(x))
const ll MAX = 2e5 + 5, MOD = 1e9 + 7;
const int dx[] = { -1, -1, 0, -1, 1, 1, 0, 1 };
const int dy[] = { 0, -1, -1, 1, 0, 1, 1, -1 };
ll fast_pow(ll a, ll p) {
    int res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = a * 1ll * a % mod;
            p /= 2;
        }
        else {
            res = res * 1ll * a % mod;
            p--;
        }
    }
    return res;
}
ull fcz(string s) {
    //return 1 if all s equal and size if there is at least one not equal
    ull x = (s + s).find(s, 1);
    return x;
}
ull gcd(ull a, ull b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ull lcm(ull a, ull b)
{
    return (a / gcd(a, b)) * b;
}
ull f(ull a) {
    return (a * (a + 1)) / 2;
}
bool isPalindrome(string S)
{
    string P = S;
    reverse(P.begin(), P.end());
    if (S == P) {
        return true;
    }
    else {
        return false;
    }
}
ull factorial(ull n) {
    ull f;
    for (f = 1; n > 1; n--)
        f = f * n % MOD;
    return f;
}

ull npr(ull n, ull r) {
    return factorial(n) / factorial(n - r);
}
ull ncr(ull n, ull r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}
ull countOdd(ull L, ull R) {
    ull N = (R - L) / 2;
    if (R % 2 || L % 2)
        N += 1;
    return N;
}
bool is_prime(ll n) {
    if (n <= 1)return false;
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)return false;
    }
    return true;
}
ll countDivisibles(ll A, ll B, ll M)
{
    if (A % M == 0)
        return (B / M) - (A / M) + 1;
    return (B / M) - (A / M);
}
ll countDivisiblesByTwoNumbers(ll N, ll A, ll B)
{
    return ceil((N / lcm(A, B)));
}
bool checkifdivisable(string& n, ll k) {
    ll rem = 0;
    for (auto i : n) {
        rem = ((rem * 10) + i - '0') % k;
    }
    return rem == 0;
}

string lower(string s) {
    for (int i = 0; i < s.length(); i++)s[i] = tolower(s[i]);
    return s;
}
string upper(string s) {
    for (int i = 0; i < s.length(); i++)s[i] = toupper(s[i]);
    return s;
}
bool is_overlapping(ll x1, ll x2, ll y1, ll y2) {
    return (max(x1, y1) < min(x2, y2));
}
ll digit(ll n) {
    return floor(log10(n) + 1);
}
void primeFactors(ll n, vll& arr)
{
    while (n % 2 == 0)
    {
        //arr.insert(2);
        arr.push_back(2);
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2)
    {
        while (n % i == 0)
        {
            //arr.insert(i);
            if (i != 1)arr.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)arr.push_back(n);
    //if (n > 2)arr.insert(n);
}
double sumpow(double n, double p)
{
    return pow(n, p + 1) - 1;
}
bool sa7e7(ld n) {
    if (ceil(n) == floor(n))return true;
    return false;
}
//vll dv;
void getDivisors(ll n, vll& dv)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dv.push_back(i);
            //st.insert(i);
            if (n % (n / i) == 0) {
                dv.push_back(n / i);
                //st.insert(n / i);
            }
        }
    }
}
ll convert(ll m, ll n)
{
    if (m == n)return 0;
    if (m > n)return m - n;
    if (n % 3 != 0)return 1 + convert(m, n + 1);
    else return 1 + convert(m, n / 3);
}
ll removeBit(ll mask, ll bit) {
    return mask & ~(1ll << bit);
}
ll addBit(ll mask, ll bit) {
    return mask | (1ll << bit);
}
string getString(char x)
{
    string s(1, x);
    return s;
}
bool perfect_square(ll n) {
    ll x = sqrt(n);
    return (x * x == n);
}
ll cnt2(ll n) {
    ll x = 0;
    while (n % 2 == 0) {
        x++; n /= 2;
    }
    return x;
}
bool pow2(ll n) {
    return !n || !(n - 1 & n);
}
ll sum_digit(ll n) {
    string s = to_string(n);
    ll sum = 0;
    for (int i = 0; i < s.length(); i++)sum += (s[i] - '0');
    return sum;
}
//*******************************************************************
ll n,k;
int arr[1000001];
ll dp[1000001];
ll sol(ll i){
  if(i==n-1){
    return 0;
  }
  if(i>=n){
    return INT_MAX;
  }
  ll &ret=dp[i];
  if(~ret)return ret;
  ll mn=abs(arr[i]-arr[i+1])+sol(i+1);
  for(int ii=2;ii<=k;ii++){
    mn=min(mn,abs(arr[i]-arr[i+ii])+sol(i+ii));
  }
  return ret=mn;
}
void Do_ur_job() {
 cin>>n>>k;
 memset(dp,-1,1000001);
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 cout<<sol(0);
  
}
int main() { //IO
    fast_in_out;
    int t = 1;
  //  cin >> t;
    for (ll i = 0; i < t; i++)Do_ur_job();
    return 0;
}