#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int a[10][10], used[10][10];

int bfs(int s, int t, int u, int v)
{
    queue<pair<int, int>> q;
    q.push({s, t});
    used[s][t] = 1;
    a[s][t] = 0;
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (x.first == u && x.second == v)
        {
            return a[u][v];
        }
        for (int k = 0; k < 8; k++)
        {
            int i1 = x.first + dx[k], j1 = x.second + dy[k];
            if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !used[i1][j1])
            {
                q.push({i1, j1});
                used[i1][j1] = 1;
                a[i1][j1] = a[x.first][x.second] + 1;
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int s, t, u, v;
        s = 8 - (s1[1] - '0') + 1;
        t = (s1[0] - '0') - 48;
        u = 8 - (s2[1] - '0') + 1;
        v = (s2[0] - '0') - 48;
        memset(used, 0, sizeof(used));
        memset(a, 0, sizeof(a));
        cout << bfs(s, t, u, v) << endl;
    }
}
