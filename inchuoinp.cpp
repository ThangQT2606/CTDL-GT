#include <bits/stdc++.h>
using namespace std;

char a[1001];
void khoitao(int n)
{
	for(int i = 1; i <= n; i++)
	{
		a[i] = '0';
	}
}

void sinh(int n)
{
	int i = n;
	while(i > 0 && a[i] == '1')
	{
		a[i] = '0';
		i--;
	}
	if(i > 0)
	{
		a[i] = '1';
	}
}
int main()
{
	int t; cin >> t;
	cin.ignore();
	while(t--)
	{
		string s;
		getline(cin, s);
		int cnt = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == ' ')
			{
				s.erase(s.begin()+i);
			}
			if(s[i] == '?')
			{
				cnt++;
			}
		}
		int l = pow(2, cnt);
		vector<string> ss(l);
		ss.assign(l, s);
		// for(int i = 0; i < ss.size(); i++)
		// {
		// 	// ss.push_back(s);
		// 	cout << ss[i] << endl;
		// }
		int tmp = 0;
		khoitao(cnt);
		for(int i = 0; i < ss.size(); i++)
		{	
			int index = 1;
			for(int j = 0; j < s.size(); j++)
			{
				if(ss[i][j] == '?')
				{
					ss[i][j] = a[index++];
				}
			}
			sinh(cnt);
			cout << ss[tmp] << endl;
			++tmp;
		}
	}
}
