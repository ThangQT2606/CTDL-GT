#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> adj[1005];
int d[1005] = {0};
bool visited[1005];
void dfs(int u)
{
    visited[u] = true;
    d[u]++;
    for(int x : adj[u])
    {
        if(!visited[x])
        {
            visited[x] = true;
            dfs(x);
        }
    }
}
int main()
{
    int k, n, m; cin >> k >> n >> m;
    int a[k+1];
    for(int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= k; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(a[i]);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] == k)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}