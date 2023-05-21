#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, k, ok = 1;
int x[15];
vector<vector<int>> v;
vector<int> prime;
bool nto(int n)
{
	if(n < 2) return false;
	else if(n == 2) return true;
	else
	{
		for(int i = 2; i <= sqrt(n); i++)
		{
			if(n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
void Try(int i, int pos, int sum)
{
	for(int j = pos; j < prime.size(); j++)
	{
		if(sum <= n)
		{
			sum += prime[j];
			x[i] = prime[j];
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
			sum -= prime[j];
		}
	}
}
int main()
{
	cin >> n >> k;
	for(int i = 2; i <= 500; i++)
	{
		if(nto(i)) prime.push_back(i);
	}
	Try(1, 0, 0);
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