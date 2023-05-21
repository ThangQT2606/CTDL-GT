#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
struct job
{
    int id, deadline, profit;
};
bool cmp(job a, job b)
{
    return a.profit > b.profit;
}
int main()
{
    int n; cin >> n;
    job a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].id >> a[i].deadline >> a[i].profit;
    }
    sort(a, a+n, cmp);
    int used[n] = {0};
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = a[i].deadline-1; j >= 0; j--)
        {
            if(!used[j])
            {
                ans += a[i].profit;
                used[j] = 1;
                break;
            }
        }
    }
    cout << ans << endl;
}