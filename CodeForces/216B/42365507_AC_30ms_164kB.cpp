#pragma comment(linker, "/STACK:16777216")  
#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <sstream>
//#include <ctime>
//#include <fstream>
using namespace std;
 
using namespace std;
 
#define INF 1000000000
#define PI acos(-1.0)
#define MP make_pair
long double EPS=1e-7;
#define MOD 1000000007 

vector<int>g[1000];

bool u[1000];

bool b;

int dfs(int x,int p){
    u[x]=1;

    int res=1;

    for (int i=0; i<g[x].size(); i++){
        if (g[x][i]==p) continue;
        if (!u[g[x][i]]) res+=dfs(g[x][i],x);
        else b=1;
    }
    return res;
}

int main(){

    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int cnt=0;

    int res=0;

    for (int i=0; i<n; i++){
        if (!u[i]){
            b=0;
            int x=dfs(i,-1);
            if (!b && x&1) cnt++;
            res+=x/2;
        }
    }

    res*=2;
    res+=cnt/2*2;
    cout<<n-res<<endl;




    
}