#include <bits/stdc++.h>
using namespace std;
// using ll = long long;
const int Mod = 1e9 + 7;
int n;

struct job
{
    long long st, ed, p;
};

bool cmp(job a, job b)
{
    return a.ed < b.ed;
}
int main()
{
    cin >> n;
    job a[n];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].st >> a[i].ed >> a[i].p;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i].st << a[i].ed << a[i].p << endl;
    // }
    sort(a + 1, a + n + 1, cmp);
    long long res = a[1].p, ok = a[1].ed;
    for (int i = 2; i <= n; i++)
    {
        if (ok < a[i].st)
        {
            ok = a[i].ed;
            res += a[i].p;
        }
    }
    cout << res << endl;
}