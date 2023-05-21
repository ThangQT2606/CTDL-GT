#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int dp[1005][1005];
int main()
{
    int n, V;
    cin >> n >> V;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i]; // khoi luong
    for (int i = 1; i <= n; i++)
        cin >> b[i]; // gia tri
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (j >= a[i])
            {
                dp[i][j] = max(b[i] + dp[i - 1][j - a[i]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][V] << endl;
}