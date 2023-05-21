#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

bool binary_s(int a[], int l, int r, int k)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == k)
        {
            return true;
        }
        else if (a[m] > k)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return false;
}
// int ok = 0;
// int binary_s(int a[], int l, int r, int x)
// {
//     int m = (l + r) / 2;
//     if (a[m] == x)
//     {
//         ok = 1;
//         return 1;  
//     }
//     else if (a[m] > x)
//     {
//         binary_s(a, l, m - 1, x);
//     }
//     else
//         binary_s(a, m + 1, r, x);
// }
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    if (binary_s(a, 0, n - 1, k))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}