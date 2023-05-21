#include <bits/stdc++.h>
using namespace std;

int n, a[100];
int used[100] = {0};
vector<vector<int>> res;

void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(!used[j])
        {
            a[i] = j;
            used[j] = 1;
            if(i == n)
            {
                vector<int> tmp(a+1, a+i+1);
                res.push_back(tmp); 
            }
            else
            {
                Try(i+1);
            }
            used[j] = 0;
        }
    }
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n;
        memset(used, 0, sizeof(used));
        Try(1);
        for(auto it = res.size()-1; it >= 0; it--)
        {
            for(int i = 0; i < n; i++)
            {
                cout << res[it][i] << " ";
            }
            cout << endl;
        }  
    }
}