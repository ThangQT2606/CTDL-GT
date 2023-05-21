#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, m;
ll dp[105][105];
int main()
{
    cin >> n >> m;
    ll a[n+1][m+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1)
            {
                if(j == 1)
                {
                    dp[i][j] = a[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j-1] + a[i][j];
                }
            }
            else
            {
                if(j == 1)
                {
                    dp[i][j] = dp[i-1][j] + a[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + a[i][j];
                }
            }
        }
    }
    cout << dp[n][m] << endl;
}