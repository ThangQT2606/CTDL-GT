#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, cnt = 0;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
int tplt[1001];
void DFS(int u)
{
    // cout << u << ' ';
    tplt[u] = cnt;
    visited[u] = true;
    for(int x : adj[u])
    {
        if(!visited[x])
        {   
            parent[x] = u;
            DFS(x);
        }
    }
}

void Path(int s, int t)
{
    memset(parent, 0, sizeof(parent));
    DFS(s);
    if(visited[t])
    {
        vector<int> path;
        while(t != s)
        {
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
        cout << "-1\n";
}
int main()
{
    cin >> n >> m >> s >> t;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Path(s, t);
}
