#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    int res = (n*(n+1))/2;
    if(res % 2 == 0)
    {
    	res /= 2;
	    vector<vector<ll>> dp(n+1, vector<ll>(res+1, 0));
	    dp[0][0] = 1;
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= res; j++)
	        {
	            if(j >= a[i])
	            {
	                dp[i][j] = (dp[i-1][j - a[i]] + dp[i-1][j])%Mod;
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j] % Mod;
	            }
	        }
	    }
	    cout << dp[n][res]%Mod << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}
