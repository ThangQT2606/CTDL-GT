#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j * j <= i)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
            // else
            // {
            //     dp[i] = dp[i-j*j];
            // }
        }
    }
    cout << dp[n] << endl;
}