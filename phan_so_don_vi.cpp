#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

void solve(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return;
    }
    if (y % x == 0)
    {
        cout << "1/" << y / x;
        return;
    }
    if (x % y == 0)
    {
        cout << x / y;
        return;
    }
    if (x > y)
    {
        int j = x / y;
        if (j == 1)
        {
            cout << "1/";
        }
        cout << j << " + ";
        solve(x % y, y);
    }
    else
    {
        int j = y / x + 1;
        cout << "1/" << j << " + ";
        solve(x * j - y, y * j);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    solve(a, b);
}