#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main()
{
    int n; cin >> n;
    cin.ignore();
    memset(a, 0, sizeof(a));
    string s;
    int tmp;
    for(int i = 1; i <= n; i++)
    {
        getline(cin, s); stringstream ss(s);
        while(ss >> tmp)
        {
            a[i][tmp] = 1;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}