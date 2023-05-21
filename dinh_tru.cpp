#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int n, m;
void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
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
    //dem so luong tplt ban dau
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
    for(int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int dem = 0;
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
    }
    cout << res << endl;
}