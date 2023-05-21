#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int F[1000005][105] = {0};
// co tong la i xet j phan tu dau tien
int main()
{
    int n, s;
    cin >> n >> s;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    F[0][0] = 1;
    for(int i = 0; i <= n; i++)
    {
        F[0][i] = 1;
    }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            
        }
    }
    cout << F[n][s] << endl;
}