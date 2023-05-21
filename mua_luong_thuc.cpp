#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, m;
        cin >> n >> s >> m;
        int an = s * m;
        int so_ngay_di_cho = 0, so_ngay_toi_da = 0;
        if (an % n == 0)
        {
            so_ngay_di_cho = an / n;
        }
        else
        {
            so_ngay_di_cho = an / n + 1;
        }
        so_ngay_toi_da = s / 7 * 6 + s % 7;
        if(so_ngay_di_cho <= so_ngay_toi_da)
        {
            cout << so_ngay_toi_da << endl;
        }
        else cout << -1 << endl;
    }
}