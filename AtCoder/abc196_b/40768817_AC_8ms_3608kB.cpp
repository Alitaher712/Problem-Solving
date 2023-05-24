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
int c(int i, string s) {
    if (i == s.size()) {
        return 0;
    }
    if (i % 2 != 0&&(s[i]>='A'&&s[i]<='Z')) {
        return 1+c(i+1,s);
   }
    else if (i % 2 == 0 && (s[i] >= 'a' && s[i] <= 'z')) {
        return 1+ c(i + 1, s);
    }
    else {
        return c(i + 1, s);
    }
}
void solve() {
    string s;
    cin >> s;
   for(int i=0;i<s.size();i++){
     if(s[i]=='.'){
       for(int j=0;j<i;j++){
         cout<<s[j];
       }
       return;
     }
   }
   cout<<s<<endl;
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