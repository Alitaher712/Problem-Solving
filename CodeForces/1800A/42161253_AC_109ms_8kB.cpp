#include <iostream>
#include <map>
using namespace std;
void solve() {
    long long n; cin >> n;
    string s; cin >> s;
    long long m = 0, e = 0, o = 0, w = 0;
    long long ind = 0;
    if (s[ind] == 'm' || s[ind] == 'M')
        while ((s[ind] == 'm' or s[ind] == 'M') && ind < n) {
                     m = 1;
                    ind++;
        }
    else {
        cout << "NO" << endl;
        return;
    }
    if (s[ind] == 'e' or s[ind] == 'E')
        while ((s[ind] == 'e' or s[ind] == 'E') && ind < n) {
            e = 1;
            ind++;
        }
    else {
        cout << "NO" << endl;
        return;
    }
    if (s[ind] == 'o' || s[ind] == 'O')
        while ((s[ind] == 'o' or s[ind] == 'O') and ind < n) {
            o = 1;
            ind++;
        }
    else {
        cout << "NO" << endl;
        return;
    }
    if (s[ind] == 'w' || s[ind] == 'W')
        while ((s[ind] == 'w' or s[ind] == 'W') and ind < n) {
            w = 1;
            ind++;
        }
    else {
        cout << "NO" << endl;
        return;
    }

    if (m == 1 && e == 1 && o == 1 && e == 1 && ind == n) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}