#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = std::sqrt(1E9);

std::vector<int> isprime(N + 1, 1);
std::vector<int> primes;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::set<int> s;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (auto p : primes) {
            if (p * p > x) {
                break;
            }
            if (x % p == 0) {
                if (s.count(p)) {
                    std::cout << "YES\n";
                    return;
                }
                s.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            if (s.count(x)) {
                std::cout << "YES\n";
                return;
            }
            s.insert(x);
        }
    }
    
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = 0;
            if (i % p == 0) {
                break;
            }
        }
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
