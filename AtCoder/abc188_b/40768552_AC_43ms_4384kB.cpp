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
int f(int ind,int*arr1,int*arr2,int n){
  if(ind==n){
    return 0;
  }
  return arr1[ind]*arr2[ind]+f(ind+1,arr1,arr2,n);
}
void solve() {
   int n;
   cin>>n;
   int arr1[n+1],arr2[n+1];
   for(int i=0;i<n;i++){
     cin>>arr1[i];
   }
   for(int i=0;i<n;i++){
     cin>>arr2[i];
   }
   if(!f(0,arr1,arr2,n)){
     cout<<"Yes\n";
   }
   else cout<<"No\n";
}
int main()
{
    int t;
//    cin >> t;
    t=1;
    while (t--) {
        solve();
    }
}