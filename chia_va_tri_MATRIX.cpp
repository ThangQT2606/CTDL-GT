#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

long n, k;
struct matrix
{
   
    ll a[1000][1000];
    //Nap chong phep nhan matrix
    friend matrix operator * (matrix x, matrix y)
    {
        matrix res;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                res.a[i][j] = 0;
                for(int k = 0; k < n; k++)
                {
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix powmod(matrix A, long n, long k)
{
    if(k == 1) return A;
    matrix x = powmod(A, n, k/2);
    if(k % 2 == 0)
    {
        return x*x;
    }
    else
    {
        return x*x*A;
    }
}
int main()
{
    matrix A;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> A.a[i][j];
        }
    }
    matrix ans = powmod(A, n, k);
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        res += ans.a[i][n-1]%mod;
    }
    cout << res << endl;
}