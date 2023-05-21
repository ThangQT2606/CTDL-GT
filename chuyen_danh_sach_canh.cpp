#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[1001];
        for(int i = 1; i <= m; i++)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            //adj[b].push_back(a);
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
}