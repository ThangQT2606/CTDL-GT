#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}
bool solve(string s)
{
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    vector<pair<char, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    int max_cnt = v[0].second;
    if(max_cnt > (s.size()+1)/2)
    {
        return false;
    }
    string result(s.length(), ' ');
    int i = 0;
    for (auto p : v) 
    {
        char c = p.first;
        int count = p.second;
        while (count--) 
        {
            // cout << c << ' ' << i << endl;
            result[i] = c;
            i += 2;
            if (i >= s.length()) 
            {
                i = 1;
            }
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if(solve(s))
        {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}