#include <iostream>
using namespace std;
int a[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<n;i++)
		{
			while(a[i]&&k)
			{
				--a[i],--k,++a[n];
			}
		}
		for(int i=1;i<=n;i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}