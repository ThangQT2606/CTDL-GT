#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

ll solve(ll n, ll m)
{
    if (m == 0)
        return 1;
    if (m == 1)
        return n % MOD;
    ll tmp = solve(n, m / 2);
    if (m % 2 == 0)
        return tmp * tmp % MOD;
    else
        return tmp * tmp % MOD * n % MOD;
}
ll so_dao(ll n)
{   
    ll res = 0, k = n;
    while (k > 0)
    {
        res = res * 10 + k % 10;
        k /= 10;
    }
    return res;
}
int main()
{
    ll n;
    cin >> n;
    ll m = so_dao(n);
    cout << solve(n, m) << endl;
}