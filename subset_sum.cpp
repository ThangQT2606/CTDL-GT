#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, a[100], ok = 0;

void Try(int i, int pos, int s, int res)
{
    for(int j = pos; j <= n; j++)
    {
        if(s + a[j] <= res)
        {
            s += a[j];
            if(s == res)
            {
                ok = 1;
                break;
            }
            else Try(i+1, j+1, s, res);
            s -= a[j];
        }
    }
}
int main()
{
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        res += a[i];
    }

    if(res % 2 == 0)
    {
        res /= 2;
        Try(1, 1, 0, res);
        if(ok)
        {
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}