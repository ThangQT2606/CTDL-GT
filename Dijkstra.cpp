#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int INF = 1e9;
using ll = long long;
int n, m, s;
vector<pair<int, int>> adj[maxn];
vector<vector<ll>> v;
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
void dijkstra(int s)
{
    vector<ll> d(n+1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // khoang cach va dinh -> lay ra dinh co khoang cach nho nhat
    q.push({0, s});
    while (!q.empty())
    {
        pair<int, int> top = q.top(); q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    vector<ll> tmp;
    for(int i = 1; i <= n; i++)
    {
        tmp.push_back(d[i]);
    }
    v.push_back(tmp);
}
int main()
{
    nhap();
    for(int i = 1; i <= n; i++)
    {
        dijkstra(i);
    }
    int q; cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << v[x-1][y-1] << endl;
    }
    // for(auto it : v)
    // {
    //     for(int i = 0; i < n; i++)
    //     {
    //         cout << it[i] << " ";
    //     }
    //     cout << endl;
    // }
}