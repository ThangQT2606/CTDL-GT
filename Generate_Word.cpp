#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;
int n, m, ok = 1;
char a[30][30];
string s, res;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool used[30][30];
void Try(int i, int j)
{
    if(res == s)
    {
        ok = 0; return;
    }
    for(int k = 0; k < 4; k++)
    {
        int i1 = i + dx[k], j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !used[i1][j1])
        {
            res += a[i1][j1];
            used[i1][j1] = true;
            if(res == s)
            {
                ok = 0;
                return;
            }
            else if(s.find(res) != string::npos)
            {
                Try(i1, j1);
            }
            used[i1][j1] = false;
            res.pop_back();
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == s[0])
            {    
                res = "";
                memset(used, false, sizeof(used));
                used[i][j] = true;
                res += a[i][j];
                Try(i, j);
            }
        }
    }
    if(!ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}