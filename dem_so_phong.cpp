#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool used[1005][1005];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int main()
{
    cin >> n >> m;
    memset(used, false, sizeof(used));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int dem = 0;
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == '.' && !used[i][j])
            {
                dem++;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> x = q.front(); q.pop();
                    for(int k = 0; k < 4; k++)
                    {
                        int ii = x.first + dx[k], jj = x.second + dy[k];
                        if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && a[ii][jj] == '.' && !used[ii][jj])
                        {
                            q.push({ii, jj});
                            used[ii][jj] = true;
                        }
                    }
                }
                
            }
        }
    }
    cout << dem << endl;
}
