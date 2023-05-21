#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, m, a[15][15], ok = 0;
void Try(int i, int j)
{
	if(i == n && j == m)
	{	
		ok++;
		return;
	}
	if(i + 1 >= 1 && i + 1 <= n && j >= 1 && j <= m && a[i+1][j])
	{	
		Try(i + 1, j);
	}
	if(i >= 1 && i <= n && j + 1 >= 1 && j + 1 <= m && a[i][j+1])
	{	
		Try(i, j + 1);
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	Try(1, 1);
	cout << ok << endl;
}