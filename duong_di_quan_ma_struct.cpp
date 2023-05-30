#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
int n, m, a[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void nhap()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
}
struct edge
{
	ll w, x, y;
};
struct CompareEdges 
{
    bool operator()(const edge& e1, const edge& e2) 
	{
        return e1.w > e2.w;
    }
};
int nn_path()
{
    ll d[n+1][m+1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = INF;
    d[1][1] = a[1][1];
	priority_queue<edge, vector<edge>, CompareEdges> q; 
	q.push({d[1][1], 1, 1});
    while (!q.empty())
    {
		edge top = q.top(); q.pop();
		int x1 = top.x;
		int y1 = top.y;
		int w1 = top.w;
        if(x1 == n && y1 == m) return w1;
        for(int k = 0; k < 4; k++)
        {
            int i1 = x1 + dx[k], j1 = y1 + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m)
            {
                if(d[x1][y1] + a[i1][j1] < d[i1][j1])
                {
                    d[i1][j1] = d[x1][y1] + a[i1][j1];
					q.push({d[i1][j1], i1, j1});
                }
            }
        }
    }
    return -1;
}
int main()
{
    nhap();
    cout << nn_path() << endl;
}
