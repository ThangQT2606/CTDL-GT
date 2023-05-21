#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, k;
string s;
char x[100];

void Try(int i, int id)
{
    for(int j = id; j < n; j++)
    {
        x[i] = s[j];
        if(i == k)
        {
            for(int pos = 1; pos <= k; pos++)
            {
                cout << x[pos];
            }
            cout << endl;
        }
        else Try(i+1, j);
    }
}
int main()
{
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    Try(1, 0);
}