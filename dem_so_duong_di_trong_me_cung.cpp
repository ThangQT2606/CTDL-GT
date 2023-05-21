#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
char a[1005][1005];
ll dp[1005][1005];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int n;
void bfs()
{
    queue<pair<int, int>> q;
    ll dem = 0;
    q.push({1, 1});
    if(a[1][1] == '*' || a[n][n] == '*')
    {
        cout << 0 << endl;
    }
    while (!q.empty())
    {
        pair<int, int> x = q.front();
        q.pop();
        if (x.first == n && x.second == n)
        {
            dem++;
            dem %= MOD;
        }
        for (int k = 0; k < 2; k++)
        {
            int i1 = x.first + dx[k];
            int j1 = x.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == '.')
            {
                q.push({i1, j1});
            }
        }
    }
    cout << dem << endl;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    // tinh toan

    if(a[1][1] == '*' || a[n][n] == '*')
    {
        cout << 0 << endl;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 && j == 1)
                {
                    dp[i][j] = 1;
                }
                if(a[i][j] == '*')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
                    dp[i][j] %= MOD;
                }
            }
        }
        cout << dp[n][n] << endl;
    }
    // bfs();
}
