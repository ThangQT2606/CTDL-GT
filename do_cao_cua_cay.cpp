#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int> adj[1005];
int d[1005] = {0};
bool visited[1005] = {false};
void dfs(int u)
{
    visited[u] = true;
    for(int x : adj[u])
    {
        if(!visited[x])
        {
            d[x] = d[u] + 1;
            visited[u] = true;
            dfs(x);
        }
       
    }
}
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n-1; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}