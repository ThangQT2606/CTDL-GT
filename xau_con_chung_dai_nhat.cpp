#include <bits/stdc++.h>
using namespace std;
int F[1001][1001];
int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();
    x = '0' + x; y = '0' + y;
    F[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(x[i] == y[j])
            {
                F[i][j] = max({1 + F[i-1][j-1], F[i-1][j], F[i][j-1]});
            }
            else
            {
                F[i][j] = max(F[i-1][j], F[i][j-1]);
            }
        }
    }
    cout << F[n][m] << endl;
}