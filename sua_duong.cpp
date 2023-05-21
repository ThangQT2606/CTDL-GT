#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 1e9;
vector<pair<int, int>> adj[1005];
int d[1005];
int n, m;

void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void search(int s)
{
    for(int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        pair<int, int> top = q.top(); q.pop();
        int kc = top.first;
        int x = top.second;
        for(auto it : adj[x])
        {
            int v = it.first; // dinh
            int w = it.second;// chi phi
            if(d[v] > d[x] + w)
            {
                d[v] = d[x] + w;
                q.push({d[v], v});
            }
        }
    }
    
} 
int main()
{
    nhap();
    int cost = 0;
    search(1);
    for(int i = 1; i <= n; i++)
    {
        cost += d[i];
        cout << d[i] << " ";
    }
    cout << cost << endl;
}