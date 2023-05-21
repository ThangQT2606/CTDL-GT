#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, u, v, ok = 0;
char a[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void ql(int i, int j, int pre, int cnt)
{
    if (cnt > 3)
    {
        return;
    }
    if (i == u && j == v)
    {
        ok = 1;
    }
    a[i][j] = '*';
    for (int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != '*')
        {
            if (k == pre)
            {
                ql(i1, j1, k, cnt);
            }
            else if (k != pre)
            {
                ql(i1, j1, k, cnt + 1);
            }
        }
    }
    a[i][j] = '.';
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'S')
            {
                s = i, t = j;
            }
            if (a[i][j] == 'T')
            {
                u = i, v = j;
            }
        }
    }
    ql(s, t, -1, 0);
    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}