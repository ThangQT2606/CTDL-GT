#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[505][505];
int dp[505][505];
int n, m;

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];	
			dp[i][j] = a[i][j];
		}	
	}
	int res = 0;	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] != 0)
			{
				if(a[i][j] == a[i-1][j-1] && a[i][j] == a[i][j-1] && a[i][j] == a[i-1][j])
				{
					dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1; 
				}
				res = max(res, dp[i][j]);
			}
			
		}
	}
//	cout << endl;
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= m; j++)
//		{
//			cout << dp[i][j] << " ";	
//		}
//		cout << endl;
//	}
	cout << res << endl;
}
