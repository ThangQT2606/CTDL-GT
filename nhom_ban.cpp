#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m, cnt = 0;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u)
{
	cnt++;
	// cout << u << ' ' << cnt << endl;
	visited[u] = true;
	for(int v : adj[u])
	{
		if(!visited[v])
			dfs(v);
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int ans = -1e9;
	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{	
			cnt = 0;
			dfs(i);
			ans = max(ans, cnt);	
		}
		
	}
	cout << ans << endl;
}