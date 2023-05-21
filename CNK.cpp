#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int n, k;

long long gt(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		return n*gt(n-1)%MOD;
	}
}

long long cnk(int n, int k)
{
	long long tu = gt(n)%MOD;
	long long mau = (gt(k)*gt(n-k))%MOD;
	return (tu/mau)%MOD;
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cout << cnk(n, k) << endl;
	}
	
}
