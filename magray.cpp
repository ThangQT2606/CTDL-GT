#include <bits/stdc++.h>
using namespace std;
string s[1001];
int main()
{
	int t; cin >> t;
	while(t--)
	{
		string a; cin >> a;
		cout << a[0];
		for(int i = 1; i < a.size(); i++)
		{
			if(a[i-1] == a[i])
			{
				cout << '0';
			}
			else
			{
				cout << '1';
			}
		}
		cout << endl;
	}
}
