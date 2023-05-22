#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[10][10], x[100];
int cot[20], duongcheo1[20], duongcheo2[20];
int res = -1e9;
void nhap()
{
	for(int i = 1; i <= 8; i++)
	{
		for(int j = 1; j <= 8; j++)
		{
			cin >> a[i][j];
		}
	}
}
void Try(int i, int sum)
{
	for(int j = 1; j <= 8; j++)
	{
		if(cot[j] == 0 && duongcheo1[8+i-j] == 0 && duongcheo2[i+j-1] == 0)
		{
			x[i] = j;
			cot[j] = duongcheo1[8+i-j] = duongcheo2[i+j-1] = 1;
			sum += a[i][x[i]];
			if(i == 8)
			{
				res = max(res, sum);
			}
			else
				Try(i + 1, sum);
				cot[j] = duongcheo1[8+i-j] = duongcheo2[i+j-1] = 0;
				sum -= a[i][x[i]];
		}
	}
}
int main()
{
	nhap();
	Try(1, 0);
	cout << res << endl;
}