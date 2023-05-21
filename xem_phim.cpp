#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int C, n;
int dp[105][25005];

int main()
{
    cin >> C >> n;
    int w[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << a[i] << " ";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j >= w[i])
            {
                dp[i][j] = max(w[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][C] << endl;
}
