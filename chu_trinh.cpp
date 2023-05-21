#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
bool check = false;
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

void DFS(int u, int par)
{
    visited[u] = true;
    for(int x : adj[u])
    {   
        //neu x da dc tham trc do va v k phai la cha cua u
        if(visited[x] && x != par)
        {
            check = true; return;
        }
        if(!visited[x])
        {
            DFS(x, u);
        }
    }
}
int main()
{
    nhap();
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            DFS(i, -1);
        }
    }
    if(check) cout << 1 << endl;
    else cout << 0 << endl;
}