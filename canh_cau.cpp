#include <bits/stdc++.h>
using namespace std;

set<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> dscanh;
int n, m;

void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        dscanh.push_back({x, y});
        adj[x].insert(y);
        adj[y].insert(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u)
{
    visited[u] = true;
    for(int x : adj[u])
    {
        if(!visited[x])
        {
            DFS(x);
        }
    }
}
int main()
{
    nhap();
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            DFS(i);
        }
    }
    int res = 0;
    for(auto it : dscanh)
    {
        int x = it.first, y = it.second;
        adj[x].erase(y);
        adj[y].erase(x);
        int dem = 0;
        memset(visited, false, sizeof(visited));
        for(int j = 1; j <= n; j++)
        {
            if(!visited[j])
            {
                dem++;
                DFS(j);
            }
        }
        if(dem > cnt)
        {
            res++;
        }
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << res << endl;
}