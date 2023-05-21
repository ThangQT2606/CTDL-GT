#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, k;
int dp[1000005];

int main()
{
    cin >> n >> k;
    dp[0] = 1;
    // cout << 'n' << ' ' << 'k' << ' ' << "dp" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i >= j)
            {
                dp[i] += dp[i - j];
            }
            dp[i] %= Mod;
            // cout << i << ' ' << j << ' ' << dp[i] << endl;
        }
    }
    cout << dp[n] << endl;
}