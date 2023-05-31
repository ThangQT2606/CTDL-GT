#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, m;
int dp[1005][1005];
int solve(int a, int b)
{
	if(a == b) return dp[a][b] = 0;
	int res = 1e9;
	if(dp[a][b]) return dp[a][b];
	for(int j = 1; j < b; j++)
	{
		res = min(res, solve(a, j) + solve(a, b - j) + 1);
	}
	for(int i = 1; i < a; i++)
	{
		res = min(res, solve(i, b) + solve(a - i, b) + 1);
	}
	return dp[a][b] = res;
}

int main()
{
	cin >> n >> m;
	cout << solve(n, m) << endl;
}