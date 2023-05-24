#include <iostream>  
using namespace std;
int f(int x,int n,int*arr) {
    if (x == n) {
        return 0;
    }
    return arr[x]+f(x + 1,n,arr);
}
int c=1;
void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout <<"Case "<<c<<": "<<f(0, n, arr)<<endl;
    c++;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}