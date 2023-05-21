#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005];
int d[1005][1005] = {0};

void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
}

int bfs()
{
    // , vector<pair<int, pair<int, int>>>
    memset(d, 0, sizeof(d));
    bool visited[1005][1005] = {false};
    queue<pair<int, int>> q;
    q.push({1, 1});
    d[1][1] = 0;
    visited[1][1] = true;
    while (!q.empty())
    {   
        pair<int, int> top = q.front();
        q.pop();
        int x = top.first, y = top.second;
        if(x == n && y == m)
        {
            return d[x][y];
            // for(int i = 1; i <= n; i++)
            // {
            //     for(int j = 1; j <= m; j++)
            //         cout << d[i][j] << " ";
            //     cout << endl;
            // }
        }
        int col1 = x;
        int row1 = y + a[x][y];
        if(col1 >= 1 && col1 <= n && row1 >= 1 && row1 <= m && !visited[col1][row1])
        {
            visited[col1][row1] = true;
            d[col1][row1] = d[x][y] + 1;
            q.push({col1, row1});
        }
        int col2 = x + a[x][y];
        int row2 = y;
        if(col2 >= 1 && col2 <= n && row2 >= 1 && row2 <= m && !visited[col2][row2])
        {
            visited[col2][row2] = true;
            d[col2][row2] = d[x][y] + 1;
            q.push({col2, row2});
        }
    }
    return -1;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        nhap();
        cout << bfs() << endl;
        // bfs();
    }
    
}