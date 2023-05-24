#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
#define mbappe ios_base::sync_with_stdio(false); cin.tie(NULL);
const ll N = 1e6+5, INF = 1e10,mod= 998244353;

ll mp[N];
//-----------------------------------------------Solve--------------------------------------------------------------------
void solve() {
    ll n;
    cin >> n;
    ll c = 0;
    vector<ll>vec(N);
    for (int i = 0; i < n; i++)cin >> vec[i], mp[vec[i]]++;
    for (ll i = 1; i < N; i++) {
        ll gc = -1;
        for (ll j = i; j < N; j+=i) {
            if (mp[j]) {
                if (gc == -1) {
                    gc = j;
                }
                else
                gc = __gcd(j, gc);
            }
        }
        c += (gc==i);
    }
    cout << c - n << el;

}

int main()
{
    int t = 1;
    //pre();
    mbappe;
  //  sieve();
 //   cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}