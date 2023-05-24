#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cnt.clear();
		int n;
		int ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			cnt[x]+=1;
			ans=max(ans,cnt[x]);
		}
		cout<<ans<<'\n';
	}
}