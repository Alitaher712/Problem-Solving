#include <iostream>  
using namespace std;
int f(int x,int n,int*arr) {
    if (x == n) {
        return 0;
    }
    return arr[x]+f(x + 1,n,arr);
}
long long Gcd(long long a, long long b){
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	while (a %= b ^= a ^= b ^= a);
	return b;
}
int c=1;
void solve() {
   int x,y;
   cin>>x>>y;
   long long p=1;
   for(int i=1;i<=min(x,y);i++){
     p*=i;
   }
   cout<<p<<endl;
}
int main()
{
    int t;
    cin >> t;
    t=1;
    while (t--) {
        solve();
    }
}