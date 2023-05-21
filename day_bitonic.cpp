#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int dp1[105], dp2[105], dp[105];

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp1[i] = max(dp1[j] + a[i], dp1[i]);
            }
        }
    }
    for (int i = n+1; i >= 1; i--)
    {
        for (int j = n+1; j > i; j--)
        {
            if (a[j] < a[i])
            {
                dp2[i] = max(dp2[j] + a[i], dp2[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << dp1[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << dp2[i] << " ";
    }
    cout << endl;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp1[i] + dp2[i] - a[i]);
    }
    cout << res << endl;
}