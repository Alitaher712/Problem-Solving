#include <iostream>  
using namespace std;
int f(int x, int n, int* arr) {
    if (x == n) {
        return 0;
    }
    return arr[x] + f(x + 1, n, arr);
}
long long Gcd(long long a, long long b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a %= b ^= a ^= b ^= a);
    return b;
}
int f(int ind, int* arr1, int* arr2, int n) {
    if (ind == n) {
        return 0;
    }
    return arr1[ind] + arr2[ind] + f(ind + 1, arr1, arr2, n);
}
long long s=0;

void solve() {
   int n;
   cin>>n;
   long long i=1;
   long long j=0;
   int c=0;
   while(j<n){
     j+=i;
     i++;
   }
   cout<<i-1<<endl;
}
int main()
{
    int t;
   // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
}