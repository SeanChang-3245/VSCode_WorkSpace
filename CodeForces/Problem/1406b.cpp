#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
ll num[100005];

bool cmp (ll l, ll r)
{
    return abs(l) > abs(r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll m;
        cin >> m;

        bool allneg = true;
        for(ll i = 0; i < m; i++)
        {
            cin >> num[i];
            if (num[i] >= 0)
                allneg = false;
        }

        if(allneg)
        {
            sort(num, num+m, greater<ll>());
            cout << num[0] * num[1] * num[2] * num[3] * num[4] << endl;
            continue;
        }

        sort(num, num + m, cmp);

        ll ans = num[0] * num[1] * num[2] * num[3] * num[4];
        for(ll i = 5; i < m; i++)
        {
            for(ll j = 0; j < 5; j++)
            {
                ll tmp = num[i];
                for(ll k = 0; k < 5; k++)
                {
                    if(k != j)
                        tmp *= num[k];
                }
                ans = max(ans, tmp);
            }
        }
        cout << ans << endl;

    }
    return 0;
}