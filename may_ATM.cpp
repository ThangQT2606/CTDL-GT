#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, s, a[100], x[100], res = 1e9, ok = 1;

void Try(int i, int pos, int sum)
{
    for (int j = pos; j <= n; j++)
    {
        if (sum + a[j] <= s)
        {
            sum += a[j];
            x[i] = a[j];
            if (sum == s)
            {
                res = min(res, i);
                ok = 0;
            }
            else
                Try(i + 1, j + 1, sum);
            sum -= a[j];
        }
    }
}
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, 1, 0);
    if (ok)
        cout << -1 << endl;
    else
        cout << res << endl;
}