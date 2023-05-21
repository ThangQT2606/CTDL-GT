#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int main()
{
    int n; cin >> n;
    int dem = 0;
    queue<string> q;
    q.push(string(1, '1'));
    while (!q.empty())
    {
        string tmp = q.front();
        q.pop();
        cout << tmp << " ";
        dem++;
        q.push(tmp + '0');
        q.push(tmp + '1');
        if(dem == n)
        {
            break;
        }
    }
    cout << endl;
}