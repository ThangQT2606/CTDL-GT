#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n, a[100];
string token;
set<int> st;
vector<string> v;
bool check()
{

    for (int i = 2; i <= n; i++)
    {   
        if (abs(a[i-1] - a[i]) <= 1) 
            return false;
    }
    return true;
}
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        a[i] = j;
        if (i == n)
        {
            if(check())
            {       
                set<int> st;
                for(int i = 1; i <= n; i++)
                {
                    st.insert(a[i]);
                }
                if(st.size() == n)
                {
                    string res = "";
                    for(int k = 1; k <= n; k++)
                    {
                        string tmp = to_string(a[k]);
                        res += tmp;
                    }
                    v.push_back(res);
                }
            }
        }
        else Try(i+1);
    }
}
int main()
{
    cin >> n;
    Try(1);
    for(auto x : v)
    {
        cout << x << endl;
    }
}