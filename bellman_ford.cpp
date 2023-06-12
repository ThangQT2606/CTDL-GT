#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
//tim duong di tu o x1, y1 den o x2, y2 tren do thi co trong so am bang bellman ford

int bellmanford(vector<vector<int>>& A, int M, int N, int x1, int y1, int x2, int y2) 
{
    vector<vector<int>> dist(M+1, vector<int>(N+1, INF));
    dist[x1][y1] = A[x1][y1];
    for (int step = 1; step < M * N; ++step) 
	{
        for (int x = 1; x <= M; ++x) 
		{
            for (int y = 1; y <= N; ++y) 
			{
                for (int k = 0; k < 4; ++k) 
				{
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    if (new_x >= 1 && new_x <= M && new_y >= 1 && new_y <= N) 
					{
                        dist[x][y] = min(dist[x][y], dist[new_x][new_y] + A[x][y]);
                    }
                }
            }
        }
    }

    return dist[x2][y2];
}

int main() 
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M+1, vector<int>(N+1));
    for (int i = 1; i <= M; ++i) 
	{
        for (int j = 1; j <= N; ++j) 
		{
            cin >> A[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bellmanford(A, M, N, x1, y1, x2, y2) << endl;
}
