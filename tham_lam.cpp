#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int k; cin >> k;
        string s; cin >> s;
        map<char, int> mp;
        priority_queue<int> q;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for(auto it : mp)
        {
            q.push(it.second);
        }
        ll res = 0;
        while(k--)
        {
            int tmp = q.top(); q.pop();
            if(tmp == 0)
            {
                break;
            }
            tmp = tmp - 1;
            q.push(tmp);
        }
        while (!q.empty())
        {
            res += (1ll)*q.top()*q.top();
            q.pop();
        }
        cout << res << endl;
    }
}