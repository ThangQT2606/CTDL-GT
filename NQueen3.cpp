#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, cot[1001], cheo1[1001], cheo2[1001], x[100];

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(cot[j] == 0 && cheo1[n+i-j] == 0 && cheo2[i+j-1] == 0)
		{
			x[i] = j;
			cot[j] = cheo1[n+i-j] = cheo2[i+j-1] = 1;
			if(i == n)
			{
				for(int row = 1; row <= n; row++)
				{
					for(int col = 1; col <= n; col++)
					{
						if(x[row] == col)
						{
							cout << "Q";
						}
						else
						{
							cout << ".";
						}
					}
					cout << endl;
				}
				cout << endl;
			}
			else Try(i + 1);
			cot[j] = cheo1[n+i-j] = cheo2[i+j-1] = 0;
		}
	}
}
int main()
{
	cin >> n;
	Try(1);
}