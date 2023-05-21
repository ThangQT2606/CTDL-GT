#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
int main()
{
    string a, b;
    cin >> a >> b;
    long long min_a = 0, max_a = 0, min_b = 0, max_b = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '5')
        {
            a[i] = '6';
        }
        max_a = max_a * 10 + (a[i] - '0');
    }
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == '6')
        {
            a[i] = '5';
        }
        min_a = min_a * 10 + (a[i] - '0');
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == '5')
        {
            b[i] = '6';
        }
        max_b = max_b * 10 + (b[i] - '0');
    }
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i] == '6')
        {
            b[i] = '5';
        }
        min_b = min_b * 10 + (b[i] - '0');
    }
    cout << max_a + max_b << " " << min_a + min_b << endl;
}