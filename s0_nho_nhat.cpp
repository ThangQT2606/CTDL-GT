#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

int main()
{
    int n, d; cin >> n >> d;
    if(n == 0 && d >= 1 || d*9 < n)
    {
        cout << -1 << endl;
        return 0;
    }
    string s = string(d, '0');
    for(int i = d-1; i >= 0; i--)
    {
        if(n > 9)
        {
            s[i] = '9';
            n -= 9;
        }
        else
        {
            if(i == 0)
            {
                s[0] = (n + '0');
            }
            else
            { 
                s[i] = (n-1) + '0';
                s[0] = '1';
            }
            break;
        }
    }
    cout << s << endl;
}