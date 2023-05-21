#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int uutien(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<char> st;
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (isalpha(s[i]))
        {
            res += s[i];
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop(); // xoa (
        }
        else
        {
            while (!st.empty() && uutien(st.top()) >= uutien(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
}