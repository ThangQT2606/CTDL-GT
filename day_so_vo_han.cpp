#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

struct matrix
{
    ll a[2][2];
    friend matrix operator*(matrix x, matrix y)
    {
        matrix res;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                res.a[i][j] = 0;
                for (int k = 0; k < 2; k++)
                {
                    res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % Mod;
                }
            }
        }
        return res;
    }
};

matrix powmod(matrix A, int n)
{
    if (n == 1)
        return A;
    matrix X = powmod(A, n / 2);
    if (n % 2 == 0)
        return X * X;
    else
        return X * X * A;
}
int main()
{
    long n;
    cin >> n;
    matrix A;
    A.a[0][0] = 1;
    A.a[0][1] = 1;
    A.a[1][0] = 1;
    A.a[1][1] = 0;
    matrix res = powmod(A, n);
    cout << res.a[0][1] << endl;
}