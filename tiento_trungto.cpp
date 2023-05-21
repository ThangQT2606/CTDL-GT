#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    stack<string> st;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        if(isalpha(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string tmp = '(' + top1 + s[i] + top2 + ')';
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}