#include<iostream>
#include<algorithm>
using namespace std;
int v[8][8], P[8];

bool rec() {
    bool ok = true;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < i; j++)
            if (P[i] - i == P[j] - j || P[i] + i == P[j] + j) return false;
    return true;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 8; i++) {
            P[i] = i;
            for (int j = 0; j < 8; j++)
                cin >> v[i][j];
        }
        int ans = 0;
        do {
            if (!rec()) continue;
            int sum = 0;
            for (int i = 0; i < 8; i++) sum += v[i][P[i]];
            ans = max(ans, sum);
        } while (next_permutation(P, P + 8));
        printf("%5d\n", ans);
    }
    return 0;
}