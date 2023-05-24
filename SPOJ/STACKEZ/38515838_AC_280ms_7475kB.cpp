#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define el endl
#define Ali ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
ll mod = 1000000007;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
unordered_map< int, vector<int> > store;
int findfreq(ll start,ll end , ll element){
        int a = lower_bound(store[element].begin(),store[element].end(),start)-store[element].begin();
        int b = upper_bound(store[element].begin(),store[element].end(),end)-store[element].begin();
        return b-a;
}
int primeFactors(int n)
{
    int c=0;
    while (n % 2 == 0)
    {
        c++;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            c++;
            n = n/i;
        }
    }
    if (n > 2){
        c++;}
        return c;
}
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
  
    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
  
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
ll ans(ll *arr,ll n,ll ele){
    ll sum=0;
    for(int i=0;i<n;i++){
        if(ele!=i){
            sum+=arr[i];
        }
    }
    return sum;
}
void assin(ll*arr1,ll *arr2,ll n){
    for(int i=0;i<n;i++){
        arr1[i]=arr2[i];
    }
}
bool check1(int *arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]>arr[n]){
            return false;
        }
    }
    return true;
}
bool check2(int *arr,int n){
    for(int i=n+1;i<n;i++){
        if(arr[i]<arr[n]){
            return false;
        }
    }
    return true;
}
stack<int>st;
void solve(){
  int n;
  cin>>n;
  if(n==1){
    int m;
    cin>>m;
    st.push(m);
  }
  else if(n==2){
    if(!st.empty()){
      st.pop();
    }
  }
  else if(n==3){
     if(!st.empty()){
      cout<<st.top()<<'\n';
    }
    else cout<<"Empty!"<<'\n';
  }
} 
int main()
{
        Ali;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }


}
