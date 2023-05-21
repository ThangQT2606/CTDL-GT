#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<int> adj[1005];
bool used[1005]= {false};
vector<pair<int, int>> kq;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    used[u] = true;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x : adj[v])
        {
            if(!used[x])
            {
                kq.push_back({v, x});
                q.push(x);
                used[x] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s;
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
    bfs(s);
    for(int i = 0; i < kq.size(); i++)
    {
        cout << kq[i].first << "->" << kq[i].second << endl;
    }
}