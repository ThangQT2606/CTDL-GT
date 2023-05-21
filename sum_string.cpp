#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s; cin >> s;
    int n = s.size();
    ll sum = 0;
    ll dp[n];
    for(int i = 0; i < n; i++)
    {
        dp[i] = s[i] - '0';
        for(int j = i - 1; j >= 0; j--)
        {
            dp[j] = (dp[j]*10) + (s[i]-'0');
        }
        for(int k = 0; k <= i; k++)
        {
            sum += dp[k];
        }
    }
    cout << sum << endl;
}