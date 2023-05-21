#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

ll n;
ll a[105][105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                a[j][i] += max(a[j][i - 1], a[j + 1][i - 1]);
            }
            else if (j == n)
            {
                a[j][i] += max(a[j][i - 1], a[j - 1][i - 1]);
            }
            else
            {
                a[j][i] += max({a[j - 1][i - 1], a[j][i - 1], a[j + 1][i - 1]});
            }
        }
    }
    ll res = -1e9;
    for (int i = 1; i <= n; i++)
    {
        if (res < a[i][n])
        {
            res = a[i][n];
        }
    }
    cout << res << endl;
    // cout << "MATRAN" << endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}