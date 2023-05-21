#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
int a[1005][1005];
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                adj[i].push_back(j);
                // adj[j].push_back(i);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] == 1)
            {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for(int it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}