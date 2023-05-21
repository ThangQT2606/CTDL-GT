#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[100], sum = 0;
int n, k, cnt = 0;
void Try(int pos, int tong)
{
	for(int j = pos; j < n; j++)
	{
		if(tong <= sum)
		{
			tong += a[j];
			if(tong == sum)
			{
				cnt++;
			}
			else
			{
				Try(j+1, tong);
			}
			tong -= a[j];
		}
			
	}
}
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int x : a)
	{
		sum += x;
	}
	if(sum % k == 0)
	{
		sum = sum / k;
		Try(0, 0);
		if(cnt == k)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		cout << 0 << endl;
	}
}