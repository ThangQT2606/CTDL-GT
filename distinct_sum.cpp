#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a)
    {
        cin >> x;
    }
    set<int> dp;
    dp.insert(0);
    for(int x : a)
    {
        set<int> tmp;
        for(auto it : dp)
        {
            tmp.insert(it + x);
        }
        dp.insert(tmp.begin(), tmp.end());
    }
    for(auto x : dp)
    {
        cout << x << " ";
    }
    cout << endl;
}