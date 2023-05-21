#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

void nhap(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int main()
{
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    vector<int> c;
    nhap(a, n);
    nhap(b, m);
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < n)
    {
        c.push_back(a[i]);
        i++;
    }
    while(j < m)
    {
        c.push_back(b[j]);
        j++;
    }
    cout << c[k-1] << endl;
}