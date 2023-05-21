#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int dp[1000005][105] = {0};
int main()
{
    int n, S;
    cin >> n >> S;
    // memset(dp, 0, sizeof(dp));
    int C[n];
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    for(int i = 0;  i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= S; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j-1];
            if (i >= C[j - 1])
            {
                dp[i][j] += dp[i-C[j-1]][j];
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[S][n] << endl;
}
