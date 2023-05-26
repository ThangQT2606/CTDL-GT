#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m, adj[1005], parent[1005];
int Find(int u)
{
	if(u == parent[u])
	{
		return u;
	}
	else return parent[u] = Find(parent[u]);
}

void Union(int u, int v)
{
//	cout << u << " " << v << endl;
	u = Find(u);
	v = Find(v);
	if(u != v)
	{
		if(adj[u] > adj[v] || (adj[u] == adj[v] && u < v))
		{
			parent[v] = u;
		}
		else
		{
			parent[u] = v;
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	vector<pair<int, int>> v;
	for(int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		adj[x]++;
		adj[y]++;
		v.push_back({x, y});
	}
	for(auto it : v)
	{
		Union(it.first, it.second);
	}
	for(int i = 1; i <= n; i++)
	{
		if(i == parent[i])
		{
			cout << i << ' ';
		}
	}
	cout << endl;
}