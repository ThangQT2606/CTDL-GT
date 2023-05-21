#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n], dp1[n], dp2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[n - 1 - i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp1[i] = a[i];
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
                dp1[i] = max(dp1[i], dp1[j] + a[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp2[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            if (b[j] < b[i])
                dp2[i] = max(dp2[i], dp2[j] + b[i]);
        }
    }
    reverse(dp2, dp2+n);
    int res = -1e9;
    for(int i = 0; i < n; i++)
    {
        res = max(res, dp1[i] + dp2[i]- a[i]);
    }
    cout << res << endl;
}
