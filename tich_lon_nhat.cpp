#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

bool cmp(int a, int b)
{
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    // for(int x : a)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    ll max1 = 1ll*(a[0]*a[1]*a[n-1]);
    ll max2 = 1ll*(a[n-1]*a[n-2]*a[n-3]);
    ll max3 = 1ll*(a[0]*a[1]);
    ll max4 = 1ll*(a[n-1]*a[n-2]);
    cout << max({max1, max2, max3, max4}) << endl;
}

// -9 -3 1 3 4