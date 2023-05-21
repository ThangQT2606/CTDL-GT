#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

ll binary_se(ll a[], int l, int r, ll x)
{
    ll res = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] <= x)
        {
            res = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return res;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long n, x;
        cin >> n >> x;
        long long a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (binary_se(a, 0, n - 1, x) != -1)
        {
            cout << binary_se(a, 0, n - 1, x) + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}