#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

struct matrix
{
    ll a[5][5];
    friend matrix operator*(matrix x, matrix y)
    {
        matrix res;
        for (int i = 0; i <=1; i++)
        {
            for (int j = 0; j <=1; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k <=1; k++)
                {
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % Mod;
                }
            }
        }
        return res;
    }
};

matrix fibo(matrix A, ll n)
{
    if (n == 1)
        return A;
    matrix X = fibo(A, n / 2);
    if (n % 2 == 0)
    {
        return X * X;
    }
    else
    {
        return X * X * A;
    }
}
int main()
{
    // ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    matrix A;
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = 0;
    ll n;
    cin >> n;
    matrix res = fibo(A, n);
    // for(int i = 0; i < 2; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //     {
    //         cout << res.a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res.a[0][1] << endl;
}