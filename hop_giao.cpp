#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m; cin >> n >> m;
        int a[n], b[m];
        set<int> s, ss;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            ss.insert(a[i]);
        }
        for(int j = 0; j < m; j++)
        {
            cin >> b[j];
            ss.insert(b[j]);
        }
        for(auto x : ss)
        {
            cout << x << " ";
        }
        cout << endl;
        for(int i = 0; i < m; i++)
        {
            if(s.count(b[i]) /*s.find(b[i]) != s.end()*/)
            {
                cout << b[i] << " ";
            }
        }
        cout << endl;
    }
}