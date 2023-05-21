#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, k, ok = 1;
int x[15];
vector<vector<int>> v;
void Try(int i, int pos, int sum)
{
	for(int j = pos; j <= 9; j++)
	{
		if(sum <= n)
		{
			sum += j;
			x[i] = j;
			if(i == k)
			{	
				if(sum == n)
				{
					ok = 0;
					vector<int> tmp(x + 1, x + i + 1);
					v.push_back(tmp);
				}
			}
			else if(sum < n)
			{
				Try(i + 1, j + 1, sum);
			}
			sum -= j;
		}
	}
}
int main()
{
	cin >> n >> k;
	Try(1, 1, 0);
	for(auto it : v)
	{
		for(int i = 0; i < it.size(); i++)
		{
			cout << it[i];
			if(i < it.size() - 1)
			{
				cout << " + ";
			}
		}
		cout << endl;
	}
	if(ok)
	{
		cout << "NOT FOUND" << endl;
	}
}