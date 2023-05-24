#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
using namespace std;
void solve() {
    long long a,b,c;
    cin >> a>>b>>c;
    cout <<abs(7-a)+abs(7-b)+abs(7-c)<< '\n';
}
int main() {
    int tc=1;
    //cin >> tc;
    while (tc--) {
        solve();
    }

}