#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s; cin >> s;
    stack<string> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i]))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string top1 = st.top(); st.pop();
            string top2 = st.top(); st.pop();
            string tmp = s[i] + top2 + top1;
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}