#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1005][1005], d[1005][1005];
int used[1005][1005];
void nhap()
{
    cin >> n >> m;
    memset(d, 0, sizeof(d));
    memset(used, 0, sizeof(used));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}

int bfs()
{
    queue<pair<int, int>> q;
    q.push({1, 1});
    used[1][1] = 1;
    d[1][1] = 0;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
    }
}
int main()
{
    nhap();
    
}