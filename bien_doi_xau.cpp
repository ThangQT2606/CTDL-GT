#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int dp[105][105];

int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    x = '0' + x;
    y = '0' + y;
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][m] << endl;
}
