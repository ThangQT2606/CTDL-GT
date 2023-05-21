#include <bits/stdc++.h>
using namespace std;
int a[100], n;
void khoitao()
{
	for(int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
}
void sinh()
{
	int i = n-1;
	while(i > 0 && a[i] > a[i+1])
	{
		i--;
	}
	cout << 'a' << endl;;
	if(i < 0)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	else
	{
		int j = n;
		while(a[i] > a[j])
		{
			j--;
		}
		swap(a[i], a[j]);
		int l = i+1 , r = n;
		while(l < r)
		{
			swap(a[l],a[r]);
			l++;
			r--;
		}
		for(int k = 1; k <= n; k++)
		{
			cout << a[k] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{	
		cin >> n;
		khoitao();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		sinh();

	}
}
