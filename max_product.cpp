#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
int main()
{
    int n; cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a, a+n);
    sort(b, b+n);
    long long res = 0;
    for(int i = 0; i < n; i++)
    {
        res += (1ll*a[i]*b[i]);
    }
    cout << res << endl;
}