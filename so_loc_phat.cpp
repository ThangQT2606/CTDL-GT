#include <bits/stdc++.h>
using namespace std;
vector<string> a;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 2;
        cin >> n;
        queue<string> q;
        q.push("6");
        a.push_back("6");
        q.push("8");
        a.push_back("8");
        while ((q.front()).size() != n)
        {
            cnt += 2;
            string v = q.front();
            q.pop();
            q.push(v + '6');
            a.push_back(v + '6');
            q.push(v + '8');
            a.push_back(v + '8');
        }
        cout << cnt << endl;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        a.clear();
    }   
}