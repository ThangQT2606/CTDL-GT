#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long s;
        queue<long long> q;
        q.push(9);
        int n;
        cin >> n;
        if (q.front() % n == 0)
            cout << 9 << endl;
        else
        {
            while (true)
            {
                long long k = q.front();
                q.pop();
                long long it1 = k * 10 + 0;
                if (it1 % n == 0)
                {
                    cout << it1 << endl;
                    break;
                }
                else
                {
                    q.push(it1);
                }
                long long it2 = k * 10 + 9;
                if (it2 % n == 0)
                {
                    cout << it2 << endl;
                    break;
                }
                else
                {
                    q.push(it2);
                }
            }
        }
    }
}