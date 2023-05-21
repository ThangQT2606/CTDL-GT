#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
const int Mod = 1e9 + 7;
int dp[105][105][105];
int main()
{
    string x, y, z;
    cin >> x >> y >> z;
    int n = x.size(), m = y.size(), v = z.size();
    x = '0' + x, y = '0' + y, z = '0' + z;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= v; k++)
            {   
                if(x[i] == y[j] && x[i] == z[k])
                    dp[i][j][k] = max({dp[i - 1][j - 1][k - 1] + 1, dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                else
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    cout << dp[n][m][v] << endl;
}