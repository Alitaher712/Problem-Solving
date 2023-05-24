#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define tle ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(b) b.begin(),b.end()
#define rall(b) b.rbegin(),b.rend()
#define INF 0x3f3f3f3f3f3f3f3f
#define sz(b) b.size()
#define F first
#define S second
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int n,m,k,x,y,x2,y2,d;
char s[N][N];
int dep[N][N],dx[] = {1,-1,0,0},dy[] = {0,0,1,-1};
int bfs(int i,int j)
{
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{i,j}});
    while(!q.empty())
    {
        i = q.front().S.F, j = q.front().S.S, d = q.front().F;
        q.pop();
        if(i == x2 && j == y2)
        {
            cout << d;
            return 0;
        }
        for(int a = 0;a < 4;++a)
        {
            for(int b = 1; b <= k;++b)
            {
                int ii = i + b * dx[a], jj = j + b * dy[a];
                if(ii < 0 || ii >= n || jj < 0 || jj >= m)
                    break;
                if(dep[ii][jj] < d + 1 || s[ii][jj] == '#')
                    break;
                if(dep[ii][jj] != d + 1)
                    q.push({d + 1,{ii,jj}}), dep[ii][jj] = d + 1;
            }

        }
    }
    return 1;
}
using namespace std;
int main() {
    tle
    cin >> n >> m >> k;
    memset(dep,INF,sizeof dep);
    for(int i = 0;i < n;++i)
    {
        for(int j = 0;j < m;++j)
            cin >> s[i][j];
    }
    cin >> x >> y >> x2 >> y2, --x,--y,--x2,--y2;
    if(bfs(x,y))
        cout << -1;
}