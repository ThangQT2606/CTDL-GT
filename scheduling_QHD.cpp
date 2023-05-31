#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
int n;

struct job
{
    ll st, ed, pro;
};

bool cmp(job a, job b)
{
    return a.ed < b.ed;
}
int lastpos(vector<pair<ll, ll>> &v, ll x)
{
	int l = 0, r = v.size() - 1, res = -1;
	while(l <= r)
	{
		int m = (l + r)/2;
		if(v[m].first < x)
		{
			res = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return res;
}
int main()
{
    cin >> n;
    job a[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].st >> a[i].ed >> a[i].pro;
    }
    sort(a+1, a+n+1, cmp);
    vector<pair<ll, ll>> v;
    v.push_back({a[1].ed, a[1].pro});
    for(int i = 2; i <= n; i++)
    {
    	ll t = lastpos(v, a[i].st), res;
    	if(t == -1)
    	{
    		res = max(a[i].pro, v[v.size() - 1].second);
		}
		else
		{
			res = max(v[v.size() - 1].second, v[t].second + a[i].pro);
		}
		v.push_back({a[i].ed, res});
	}
	cout  << v[v.size() - 1].second << endl;
}