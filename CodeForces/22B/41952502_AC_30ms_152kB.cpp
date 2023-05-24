#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string str[30];
bool boxHas(int startRow, int endRow, int startCol, int endCol)
{
	for (int i = startRow; i <= endRow; i++)
	{
		for (int j = startCol; j <= endCol; j++)
		{
			if (str[i][j] == '1') return true;
		}
	}
	return false;
}
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	int ans = 0;
	for (int startRow = 0; startRow < n; startRow++)
	{
		for (int endRow = startRow; endRow < n; endRow++)
		{
			for (int startCol = 0; startCol < m; startCol++)
			{
				for (int endCol = startCol; endCol < m; endCol++)
				{
					if (boxHas(startRow, endRow, startCol, endCol)) {
						continue;
					}
					ans = max(ans, (endRow - startRow + 1) * 2 + (endCol - startCol + 1) * 2);
				}
			}
		}
	}

	cout << ans << endl;
}