#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
ll a[64];

void thapphan()
{
    for(int i = 0; i < 64; i++)
    {
        a[i] = pow(2, i);
    }
}
int main()
{   
    thapphan();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        while (n > 0)
        {
            st.push(n % 2);
            n /= 2;
        }
        string s = "", ans = "";
        while (!st.empty())
        {
            char tmp = st.top() + '0';
            s = s + tmp;
            st.pop();
        }
        ans = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
            {
                ans += '0';
            }
            else
                ans += '1';
        }
        // cout << ans << endl;
        reverse(ans.begin(), ans.end());
        int res = 0;
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i] == '1')
            {
                res += a[i];
            }
        }
        cout << res << endl;
    }
}