#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
int main()
{
    // int t; cin >> t;
    // while(t--)
    // {

    // }
    int n; cin >> n;
    int a[n+1][n+1];
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
        cout << i << ": ";
        for(auto it : adj[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}