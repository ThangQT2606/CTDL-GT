#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, a[105], x[105], cnt = 0;
vector<string> v;
void Try(int i, int pos)
{
    for(int j = pos; j <= n; j++)
    {
        if(x[i-1] < a[j])
        {
            x[i] = a[j];
            cnt++;
            if(i >= 2)
            {   
                string res = "";
                for(int k = 1; k <= i; k++)
                {
                    string tmp = to_string(x[k]);
                    res += tmp;
                    res += ' ';
                }
                v.push_back(res);
            }
            Try(i+1, j+1);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    Try(1, 1);
    sort(v.begin(), v.end());
    for(auto it : v)
    {
        cout << it << endl;
    }
}