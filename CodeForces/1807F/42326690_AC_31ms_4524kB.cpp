#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "map"
#include "bitset"
#include "set"
#include "numeric"
#include "iomanip"
#include "random"

#define sz(x) (int)(x.size())
#define ll long long
#define int long long
#define pii pair <int, int>
#define x first
#define y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

void solve() {
    ll n, m, x1, y1, y2, x2;
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    vector <vector <int> > v(n + 1, vector <int> (m + 1, 1e9));
    vector <vector <vector <bool> > > f(n + 1, vector <vector <bool> > (m + 1, vector <bool> (5)));
    map <string, pii> mp;
    map <string, int> mp1;
    map <char, char> rev;
    rev['D'] = 'U';
    rev['U'] = 'D';
    rev['R'] = 'L';
    rev['L'] = 'R';
    mp["DR"] = {1, 1};
    mp1["DR"] = 0;
    mp["DL"] = {1, -1};
    mp1["DL"] = 1;
    mp["UR"] = {-1, 1};
    mp1["UR"] = 2;
    mp["UL"] = {-1, -1};
    mp1["UL"] = 3;
    string s;
    cin >> s;
    int cnt = 0;

    while (true) {
        auto p = mp[s];
        int ff = 0;
        if (y1 + p.x == 0 || y1 + p.x == n + 1) {
            s[0] = rev[s[0]];
            ff = 1;
        }
        if (x1 + p.y == 0 || x1 + p.y == m + 1) {
//            cout << x1 + p.y << " " << m + 1 << "\n";
            s[1] = rev[s[1]];
            ff = 1;
        }
//        cout << y1 << " " << x1 << " " << ff << " " << s << "\n";
        v[y1][x1] = min(v[y1][x1], cnt);
        cnt += ff;
        if (ff) {
            if (f[y1][x1][mp1[s]]) break;
        }

//        cout << "oih u \n";
        f[y1][x1][mp1[s]] = true;
        p = mp[s];
        x1 += p.y;
        y1 += p.x;
//        cout << y1 << " " << x1 << "\n";
        if (f[y1][x1][mp1[s]]) break;
        f[y1][x1][mp1[s]] = true;
        v[y1][x1] = min(v[y1][x1], cnt);
    }
    if (v[y2][x2] == 1e9) {
        cout << "-1\n";
    } else {
        cout << v[y2][x2] << "\n";
    }
//    cout << endl;
}


signed main() {
//    freopen("monument.in", "r", stdin);
//    freopen("monument.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

