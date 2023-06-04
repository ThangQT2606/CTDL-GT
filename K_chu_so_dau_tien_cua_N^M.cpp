#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
int n, m, k;

void tinh(int s[], int &pos)
{
	int nho = 0;
	for(int i = 0; i < pos; i++)
	{
		nho = s[i]*n + nho;
		s[i] = nho%10;
		nho /= 10;
	}
	while(nho > 0)
	{
		s[pos++] = nho%10;
		nho /= 10;
	}
}
void in(int s[], int pos)
{
	for(int i = pos - 1; i >= 0; i--)
	{
		if(k > 0)
		{
			cout << s[i];
			--k;
		}
	}
	cout << endl;
}
void solve()
{
	int res[100000], pos = 1;
	res[0] = n;
	for(int i = 1; i < m; i++)
	{
		tinh(res, pos);
	}
	in(res, pos);
}
int main()
{
	cin >> n >> m >> k;
	solve();
}