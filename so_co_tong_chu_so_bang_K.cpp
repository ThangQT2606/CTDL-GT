#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
#define endl '\n'

int n, k;
int dp[105][50005];
int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
// i chu so co tong la k
int main()
{
	cin >> n >> k;
	for(int j = 1; j <= 9; j++)
	{
		dp[1][j] = 1;
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= k; j++)
		{
			for(int m = 0; m < 9; m++)
			{
				if(j >= a[m])
				{
					dp[i][j] += dp[i-1][j - a[m]];
//							m = 0	m = 1  m = 2
//					2 2; -> 1 2  +  1 1 +  1 0 = 1 + 1 + 0
					dp[i][j] %= Mod;
				}
			}
		}
	}
	cout << dp[n][k] << endl;
}
