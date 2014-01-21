#include <iostream>
#include <vector>
#define  sz(X)  (int)X.size()
using namespace std;
typedef vector<int> vi;

int n;
int m;
int ft[300000][2];
int res;
vi  gr[100000];
bool vis[100000];
bool clr[100000];

bool dfs(int v, bool c, int pr)
{
	vis[v] = 1;
	clr[v] = c;
	
	for (int i = 0; i < sz(gr[v]); i++)
	{
		int u = gr[v][i];
		
		if (u == pr)
			continue;
		
		if (vis[u] && clr[v] == clr[u])
			return 0;
		if (!vis[u] && !dfs(u,c^1,v))
			return 0;
	}
	
	return 1;
}

bool isok(int k)
{
	for (int v = 0; v < n; v++)
		gr[v].clear();
	
	for (int i = 0; i < k; i++) {
		gr[ ft[i][0] ].push_back( ft[i][1] );
		gr[ ft[i][1] ].push_back( ft[i][0] );
	}
	
	fill(vis, vis+100000, 0);
	fill(clr, clr+100000, 0);
	
	for (int v = 0; v < n; v++)
		if (!vis[v] && !dfs(v,0,-1))
			return 0;
	
	return 1;
}

int main()
{
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		cin >> ft[i][0];
		cin >> ft[i][1];
		
		ft[i][0]--;
		ft[i][1]--;
	}
	
	int lo = 0;
	int hi = m;
	
	res = 0;
	while (lo <= hi)
	{
		int md = (lo+hi)/2;
		
		if (isok(md))
		{
			lo = md+1;
			res = max(res, md);
		}
		else
			hi = md-1;
	}
	
	cout << res+1;
	
	return 0;
}
