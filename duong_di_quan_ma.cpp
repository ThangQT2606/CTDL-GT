#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 1005;
const int INF = 1e9;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[MAX_SIZE][MAX_SIZE];
int shortestPath(int N, int board[][MAX_SIZE], int x1, int y1, int x2, int y2)
{
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    dist[x1][y1] = board[x1][y1];
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({dist[x1][y1], {x1, y1}});
    while (!q.empty())
    {
        pair<int, pair<int, int>> top = q.top();
        int w = top.first;
        int x = top.second.first;
        int y = top.second.second;
        q.pop();
        if (x == x2 && y == y2)
        {
            return w;
        }
        for (int i = 0; i < 8; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 1 && newX <= N && newY >= 1 && newY <= N)
            {
                if (dist[x][y] + board[newX][newY] < dist[newX][newY])
                {
                    dist[newX][newY] = dist[x][y] + board[newX][newY];
                    q.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cin >> board[i][j];
            }
        }
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // if(shortestPath(N, board, x1, y1 ,x2, y2) == INF) cout << -1 << endl;
        // else cout << shortestPath(N, board, x1, y1 ,x2, y2) << endl;
        cout << shortestPath(N, board, x1, y1, x2, y2) << endl;
    }
}
// 5
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
// 1 1 5 5
