#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll n;
vector<vector<ll>> dist;

ll StoIdx(int k)
{
    return (ll)(log2(k));
}

ll C(ll set, ll cur, ll size)
{
    if(size == 1)
        return 0;

    if(size == 2)
        return dist[0][cur];

    ll res = INT_MAX;
    for(int i = 1; i < n; i++)
    {
        ll last = 1 << i;
        if(((last & set) != 0) && i != cur)
        {
            ll idx = StoIdx(last);
            ll tmp = C(set ^ last, idx, size-1) + dist[idx][cur];
            if(tmp < res)
                res = tmp;
        }
    }

    printf("C(%lld, %lld, %lld) = %lld", set, cur, size, res);
    cout << endl;
    return res;
}


int main()
{
    cin >> n;
    dist.resize(n);

    for(int i = 0; i < n; i++)
    {
        dist[i].resize(n);
        for(int j = 0; j < n; j++)
            cin >> dist[i][j];
    }

    ll tmp = 0;
    for(int i = 0; i < n; i++)
    {
        tmp |= (1 << i);
    }

    cout << "tmp: " << tmp << endl;

    ll ans = INT_MAX;
    int ni;
    for(int i = 1; i < n; i++)
    {
        ll cur = 1 << i;
        int k = C(tmp ^ cur, i, n) + dist[i][0];
        if(k < ans)
        {
            ans = k;
            ni = i;
        }
    }
    cout << ni << endl;
    cout << ans;
    return 0;
}