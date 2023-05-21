#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int solve(string s)
{
    stack<int> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            st.push(s[i] - '0');
        }
        else
        {
            int top1 = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            if(s[i] == '+')
            {
                int tmp = top1 + top2;
                st.push(tmp);
            }
            if(s[i] == '-')
            {
                int tmp = top1 - top2;
                st.push(tmp);
            }
            if(s[i] == '*')
            {
                int tmp = top1 * top2;
                st.push(tmp);
            }
            if(s[i] == '/')
            {
                int tmp = top1 / top2;
                st.push(tmp);
            }
        }
    }
    return st.top();
}
int main()
{
    string s; cin >> s;
    cout << solve(s) << endl;
}