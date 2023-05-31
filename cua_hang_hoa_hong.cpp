#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int main()
{
	int n; cin >> n;
	ll a[n + 5];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int T[n + 5] = {0}, G[n + 5] = {0};
	T[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		if(a[i - 1] < a[i])
		{
			T[i] = T[i-1] + 1;
		}
		else
		{
			T[i] = 1;
		}
	}
	G[n] = 1;
	int res = -1e9;
	for(int i = n - 1; i >= 1; i--)
	{
		if(a[i] < a[i+1])
		{
			G[i] = G[i+1] + 1;
		}
		else
		{
			G[i] = 1;
		}
		res = max(res, G[i]);
	}
	for(int i = 2; i < n; i++)
	{
		if(a[i-1] < a[i+1])
		{
			res = max(res, T[i-1] + G[i+1]);
		}
	}
	cout << res << endl;
}