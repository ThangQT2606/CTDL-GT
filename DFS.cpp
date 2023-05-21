#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
int n, m, u;
vector<int> adj[1001];
bool visited[1001];
void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for(auto x : adj[u])
    {
        if(!visited[x])
        {
            DFS(x);
        }
    }
}
int main()
{
    cin >> n >> m >> u;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
    DFS(u);
    cout << endl;
}