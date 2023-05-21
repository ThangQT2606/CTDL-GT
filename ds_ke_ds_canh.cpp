#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1005];
int a[1005][1005];
pair<int, int> ke[1005];
int main()
{
    int n; cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++)
    {
        string s; 
        getline(cin, s);
        int tmp;
        stringstream ss(s);
        // vector<int> v;
        while(ss >> tmp)
        {
            a[i][tmp] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j])
            {
                cout << i << " " << j << endl;
                // a[j][i] = 0;
            }
        }
    }
}