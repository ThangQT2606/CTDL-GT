#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n;
int dp[105][105];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> dp[i][j];
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j == 1)
            {
                dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
            }
            else if(j == n)
            {
                dp[i][j] += max(dp[i-1][j+1], dp[i-1][j]);
            }
            else
            {
                dp[i][j] += max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]});
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << *max_element(dp[n]+1, dp[n]+1+n) << endl;
}