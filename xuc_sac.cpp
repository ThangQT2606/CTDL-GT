#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int dp[1000001];
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {   
            if(i >= j)
            {
                dp[i] += dp[i - j];
                dp[i] %= Mod;
            }
        }
    }
    cout << dp[n] << endl;
}