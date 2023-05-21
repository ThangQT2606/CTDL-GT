#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

string chuanHoa(string &s)
{
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        chuanHoa(s);
        int L[s.size()];
        for(int i = 0; i < s.size(); i++)
        {
            L[i] = 1;
        }
        int dem = 0;
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(s[j] < s[i])
                {
                    L[i] = max(L[i], L[j] + 1);
                }
            }
        }
        cout << *max_element(L, L+s.size()) << endl;
    }
}