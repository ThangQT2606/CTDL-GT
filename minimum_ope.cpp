#include <bits/stdc++.h>
using namespace std;
int d[10005];

int bfs(int s, int t)
{
    set<int> st;
        queue<int> q;
        q.push(s);
        st.insert(s);
        d[s] = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            if (top == t)
            {
                return d[t];
            }
            if (!st.count(top * 2))
            {
                q.push(top * 2);
                st.insert(top * 2);
                d[top * 2] = d[top] + 1;
            }
            if (!st.count(top - 1) && top - 1 > 0)
            {
                q.push(top - 1);
                st.insert(top - 1);
                d[top - 1] = d[top] + 1;
            }
        }
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t) << endl;
    }
}
