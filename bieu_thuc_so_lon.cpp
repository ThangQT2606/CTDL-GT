#include <bits/stdc++.h>
using namespace std;
#define end '\n'
const int MOD = 10;
//Tinh gia tri cua bieu thuc S = n!/(n-k)!
int n, k; 
int s[100000];
void tinh(int &pos, int x)
{
	int nho = 0;
	for(int i = 0; i < pos; i++)
	{
		nho = s[i]*(n-k+1+x) + nho;
		s[i] = nho%MOD;
		nho = nho/MOD;
	}
	while(nho > 0)
	{
		s[pos++] = nho%MOD;
		nho /= MOD;
	}
}
void in(int pos)
{
	for(int i = pos - 1; i >= 0; i--)
	{
		cout << s[i];
	}
	cout << endl;
}
void solve()
{
	int pos = 1;
	s[0] = n-k+1;
	for(int i = 1; i < k; i++)
	{
		tinh(pos, i);
	}
	in(pos);
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> k;
		solve();
	}
}