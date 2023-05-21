#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
int n, m, s, t, u, v, a[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> s >> t >> u >> v;
}

int nn_path()
{
    ll d[n+1][m+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = INF;
    d[s][t] = a[s][t];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({d[s][t], {s, t}});
    while (!q.empty())
    {
        pair<int, pair<int, int>> top = q.top(); q.pop();
        int w = top.first;
        int x = top.second.first;
        int y = top.second.second;
        if(x == u && y == v) return w;
        for(int k = 0; k < 4; k++)
        {
            int i1 = x + dx[k], j1 = y + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m)
            {
                if(d[x][y] + a[i1][j1] < d[i1][j1])
                {
                    d[i1][j1] = d[x][y] + a[i1][j1];
                    q.push({d[i1][j1], {i1, j1}});
                }
            }
        }
    }
    return -1;
}
int main()
{
    nhap();
    cout << nn_path() << endl;
}
