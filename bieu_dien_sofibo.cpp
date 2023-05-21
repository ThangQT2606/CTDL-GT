#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int a[10001], x[10001], dp[100][100005];
int n, k;
vector<vector<int>> v;
void khoitao()
{
    a[1] = 1; a[2] = 2;
    for(int i = 3; i < 27; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
}

// void Try(int i, int pos, int S)
// {
//     for(int j = pos; j <= 26; j++)
//     {
//         if(S + a[j] <= n)
//         {   
//             x[i] = a[j];
//             S += a[j];
//             // if(i == k)
//             // {
//                 if(S == n)
//                 {
//                     cnt++;
//                     vector<int> tmp(x+1, x+i+1);
//                     v.push_back(tmp);
//                 }
//                 // else
//                 Try(i+1, j+1, S);
//                 S -= a[j];

//         }
//     }
// }
int main()
{
    khoitao();
    cin >> n;
    // Try(1, 1, 0);
    // for(auto it : v)
    // {
    //     for(int i = 0; i < it.size(); i++)
    //     {
    //         cout << it[i] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << cnt << endl;
    dp[0][0] = 1;
    dp[1][1] = 1;
    for(int i = 1; i < 27; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 2; i <= 26; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j >= a[i])
            {
                dp[i][j] = dp[i-1][j-a[i]] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << dp[26][n] << endl;
}