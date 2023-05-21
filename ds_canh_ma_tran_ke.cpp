#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    int n, m; cin >> n >> m;
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}