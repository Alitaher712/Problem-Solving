#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int n;
bool v[17];
int ans[17], primes[32] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1 };
void rec(int ind) {
	if ((ind == n) && (primes[ans[ind - 1] + ans[0]])) {
		for (int i = 0; i < n; i++) {
			if (i == 0) cout << ans[i];
			else cout << " " << ans[i];
		}
		cout << endl;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (v[i] == 0) {				
				if (primes[ans[ind - 1] + i]) {		
					ans[ind] = i;			
					v[i] = 1;			
					rec(ind + 1);			
					v[i] = 0;				
				}
			}
		}
	}
}
void WEKA() {
	int ca = 1;
	while (cin >> n) {
		if (ca > 1) cout << endl;
		cout << "Case " << ca++ << ":" << endl;
		memset(v, 0, sizeof(v));		
		ans[0] = 1;		
		v[1] = true;		
		rec(1);			
	}
}
int main() {
    int t = 1;
  //   cin >> t;
    while (t--) {
        WEKA();
    }
    return 0;
}