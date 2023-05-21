#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int dp[105][1000001];
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (j >= a[i])
            {
                dp[i][j] = dp[i][j - a[i]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][j] %= Mod;
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[n][s] << endl;
}