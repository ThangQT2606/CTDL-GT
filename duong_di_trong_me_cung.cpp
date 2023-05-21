#include <bits/stdc++.h>
using namespace std;

int n, s, t, u, v;
int a[1005][1005];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int d[1005][1005]; // so buoc di chuyen toi thieu tu s, t den u, v
bool visited[1005][1005];
struct dta
{
    int x, y;
};

int bfs(int i, int j) // di tu s, t
{
    queue<dta> q;
    q.push({i, j});
    visited[i][j] = true;
    while(!q.empty())
    {
        dta top = q.front();
        q.pop();
        if(top.x == u && top.y == v) return d[u][v]; 
        int i1 = top.x, j1 = top.y;
        for(int i = 0; i < 8; i++)
        {
            int inew = i1 + dx[i];
            int jnew = j1 + dy[i];
            if(inew >= 1 && inew <= n && jnew >= 1 && jnew <= n && a[inew][jnew] && !visited[inew][jnew])
            {
                q.push({inew, jnew});
                visited[inew][jnew] = true;
                d[inew][jnew] = d[i1][j1] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> s >> t >> u >> v;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(d, 0, sizeof(d));
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(a[u][v] == 1)
    {
        cout << bfs(s, t) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    // cout << bfs(s, t) << endl;
}