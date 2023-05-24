#include<bits/stdc++.h>
using namespace std;
long long i, l, r, t, a[1200];
queue<long long>Q;
long long s(long long k)
{
	for (i = t = 0; a[++i] < k;) {
		t += a[i] * (a[i] - a[i - 1]);
	}
	return t + a[i] * (k - a[i - 1]);
}
int main()
{
	for (Q.push(0); Q.front() < 4444444447LL; Q.pop())
	{
		a[i++] = Q.front();
		Q.push(10 * Q.front() + 4);
		Q.push(10 * Q.front() + 7);
	}
	cin >> l >> r;
	cout << s(r) - s(l - 1);
}