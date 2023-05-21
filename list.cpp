#include <bits/stdc++.h>
using namespace std;

int main() 
{
    stack<int> st;
    st.push(21);
    st.push(22);
    st.push(24);
    st.push(25);
    int x = st.top();
    st.pop(); 
    int y = st.top();
    st.pop();
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
