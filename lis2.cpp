#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int first_pos(vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (v[m] >= x)
        {
            res = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return res;

}
int main()
{
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    for (int &x : a)
    {
        cin >> x;
    }
    for (int i = 0; i < n; i++)
    {
        int check = first_pos(v, a[i]);
        if(check != -1)
        {
            v[check] = a[i];
        }
        else
        {
            v.push_back(a[i]);
        }
    }
    cout << v.size() << endl;
}