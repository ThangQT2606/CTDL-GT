#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
int n, m, u;
vector<int> adj[1001];
bool visited[1001];
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : adj[v])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
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
    BFS(u);
    cout << endl;
}

