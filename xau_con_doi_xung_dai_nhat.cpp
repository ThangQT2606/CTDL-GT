#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        s = 'x' + s;
        int n = s.size(), ans = 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                if(len == 2)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    if(dp[i+1][j-1] && s[i] == s[j])
                    {
                        dp[i][j] = 1;
                    }
                }
                if(dp[i][j])
                {
                    ans = max(ans, len);
                }
            }
        }
        cout << ans << endl;
    }
}