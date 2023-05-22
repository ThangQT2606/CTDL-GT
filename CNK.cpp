#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
const int MOD = 1e9+7;
ll dp[1005][1005];

int main()
{
	int n, k; cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k] << endl;
}