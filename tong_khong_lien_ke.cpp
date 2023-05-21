#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    int a[n + 1], dp[n + 1] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    }
    cout << dp[n] << endl;
}