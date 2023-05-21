#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool ok = true;
        for (int s7 = n / 7; s7 >= 0; s7--)
        {
            int k = n - s7 * 7;
            if (k % 4 == 0)
            {
                for (int j = 0; j < k / 4; j++)
                {
                    cout << 4;
                }
                for (int j = 0; j < s7; j++)
                {
                    cout << 7;
                }
                ok = false;
                cout << endl;
                break;
            }
        }
        if (ok)
            cout << -1 << endl;
    }
}