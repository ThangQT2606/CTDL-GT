#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        pair<int, int> p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].second;
                }
        sort(p, p + n, cmp);
        long tmp = -1e9, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (tmp <= p[i].first)
            {
                tmp = p[i].second;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}