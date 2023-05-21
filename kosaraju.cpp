#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> ke[1005], r_ke[1005];
bool visited[1005];
stack<int> st;

void inp()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        r_ke[y].push_back(x);
    }
}

void dfs1(int u)
{
    visited[u] = true;
    for(int v : ke[u])
    {
        if(!visited[v])
        {
            dfs1(v);

        }
    }
    st.push(u);
}

void dfs2(int u)
{
    visited[u] = true;
    // cout << u << " ";
    for(int v : r_ke[u])
    {
        if(!visited[v])
        {
            dfs2(v);
        }
    }
}

void SCC()
{
    memset(visited, false, sizeof(visited));
    //B1: goi dfs tren do thi ban dau
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            dfs1(i);
        }
    }
    // cout << endl;
    memset(visited, false, sizeof(visited));
    while(!st.empty())
    {
        int u = st.top(); st.pop();
        if(!visited[u])
        {   
            cnt++;
            dfs2(u);
            // cout << endl;
        }
    }
    if(cnt == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
int main()
{
    inp();
    SCC();
}