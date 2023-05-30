#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 1; i * i <= N; i++) 
	{
        v.push_back(i * i);
    }
    int m = v.size();
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 1e9));
//    dp[0][0] = 0;
    for(int i = 0; i <= m; i++)
    {
    	dp[i][0] = 0;
	}
    for (int i = 1; i <= m; i++) 
	{
        for (int j = 1; j <= N; j++) 
		{
            if (j >= v[i - 1]) 
			{
                dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i - 1]] + 1);
            } 
			else 
			{
                dp[i][j] = dp[i - 1][j];
            }
//            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[m][N] << endl;
}
