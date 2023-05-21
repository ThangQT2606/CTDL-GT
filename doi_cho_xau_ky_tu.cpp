#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b)
{
    return int(a) > int(b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        string s, res;
        cin >> k >> s;
        res = s;
        sort(res.begin(), res.end(), cmp);
        // reverse(res.begin(), res.end());
        for (int i = 0; i < k; i++)
        {
            if (s[i] != res[i])
            {
                for (int j = i + 1; j < s.size(); j++)
                {
                    if (s[j] == res[i])
                    {
                        swap(s[i], s[j]);
                    }
                }
            }
        }
        cout << s << endl;
    }
}