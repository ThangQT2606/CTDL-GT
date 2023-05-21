#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
ll dp[100005][105];
// xet i phan tu co ja tri la j
int main() 
{
    int n, m; cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if(a[1] > 0) dp[1][a[1]] = 1;
    else
    {
        for(int j = 1; j <= m; j++)
        {
            dp[1][j] = 1;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == 0)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= Mod;
            }
        }
        else
        {
            dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + dp[i-1][a[i]+1];
            dp[i][a[i]] %= Mod;
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    // cout << res << endl;
}