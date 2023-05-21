#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n, a[1005], x[1005], ok = 1;
vector<vector<int>> v;
void Try(int i, int sum, int pos)
{
    for(int j = pos; j < n; j++)
    {
        x[i] = a[j];
        sum += x[i];
        if(sum % 2 != 0)
        {
            ok = 0;
            vector<int> tmp(x+1, x+i+1);
            v.push_back(tmp);
        }
        Try(i + 1, sum, j + 1);
        sum -= a[j];
    }
}
int main()
{
    cin >> n; 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
//    sort(a, a+n);
    Try(1, 0, 0);
    sort(v.begin(), v.end());
    if(ok)
    {
        cout << "NOT FOUND" << endl;
    }
    else
    {
        for(auto it : v)
        {
            for(int i = 0; i < it.size(); i++)
            {
                cout << it[i] << " ";
            }
            cout << endl;
        }
    }
}