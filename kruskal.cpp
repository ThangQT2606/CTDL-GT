#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

struct edge
{
    ll x, y, w;
};

int sz[100005], parent[100005];
int n, m;
vector<edge> dscanh;

void init()
{
    for (int i = 1; i <= 100000; i++)
    {
        sz[i] = 1;
        parent[i] = i;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
    {
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

void nhap()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edge e{x, y, w};
        dscanh.push_back(e);
    }
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void Kruskal()
{
    // B1 : Sx danh sach canh
    sort(dscanh.begin(), dscanh.end(), cmp);
    ll d = 0;
    vector<edge> mst; // luu canh cay khung
    // B2 : duyet va chon
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break; // du canh
        edge tmp = dscanh[i];
        if (Union(tmp.x, tmp.y))
        {
            d += tmp.w;
            mst.push_back(tmp);
        }
    }
    if (mst.size() < n - 1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << d << endl;
        // for (edge X : mst)
        // {
        //     cout << X.x << ' ' << X.y << ' ' << X.w << endl;
        // }
    }
}

int main()
{

    init();
    nhap();
    Kruskal();
}