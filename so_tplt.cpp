#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1005];
bool visited[1005];
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
    cin >> n >> m;
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= m; i++)
    {
        int x , y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            //memset(visited, false, sizeof(visited));
            DFS(i);
        }
    }
    cout << cnt << endl;
}