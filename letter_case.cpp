#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
string s, res = "";
int n;
void Try(int pos)
{	
	for(int j = pos; j < n; j++)
	{
		if(isdigit(s[j]))
		{
			res += s[j];
			if(res.size() == n)
			{
				cout << res << endl;
			}
			else
				Try(j + 1);
			res.pop_back();
		}
		else
		{
			char c = toupper(s[j]);
			char d = tolower(s[j]);
			for(char x : {c, d})
			{
				res += x;
				if(res.size() == n)
				{
					cout << res << endl;
				}
				else
					Try(j + 1);
				res.pop_back();
			}		
		}
	}
}
int main()
{
	cin >> s;
	n = s.size();
	Try(0);
}