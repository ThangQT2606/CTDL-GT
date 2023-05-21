#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int dp[100005][1005], a[100005];
//xet i phan tu dau tien co tong la j
int main()
{
	int n, m; cin >> n >> m;
	int id = 0;
	for(int i = 1; pow(i, m) <= n; i++)
	{
		a[i] = pow(i, m);
		id++;
	}
	for(int i = 1; i <= id; i++)
	{
		dp[i][0] = 1;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= id; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j >= a[i])
			{
				dp[i][j] = dp[i-1][j - a[i]] + dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
//			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	cout << dp[id][n] << endl;
}
