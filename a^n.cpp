#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

ll powmod(ll a, ll n)
{
    if (n == 1)
        return a;
    ll tmp = powmod(a, n / 2);
    if (n % 2 == 0)
    {
        return tmp * tmp;
    }
    else
    {
        return tmp * tmp * a;
    }
}
int main()
{
    ll  n;
    cin >> n;
    ll res = powmod(2, n-1);
    cout << res << endl;
}