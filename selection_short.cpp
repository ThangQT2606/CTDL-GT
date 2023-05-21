#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

// void doi_cho(int &x, int &y)
//{
//     swap(x, y);
// }
void solve(int a[], int n)
{
    int i, j, min_idx;
    for(i = 0; i < n-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < n; j++)
            if(a[j] < a[min_idx])
                min_idx = j;
                swap(a[min_idx], a[i]);
        cout << "Buoc " << i+1 << ": ";
        for(int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
// 64 25 12 22 11
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);
}