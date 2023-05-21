#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int dp[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m = i;
        dp[i] = 1e9;
        while (m)
        {
            int r = m % 10;
            m /= 10;
            // if(r > 0)
            // {
            dp[i] = min(dp[i], dp[i - r] + 1);
            // }
        }
    }
    cout << dp[n] << endl;
}
