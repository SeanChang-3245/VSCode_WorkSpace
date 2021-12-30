#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, cnt = 0, MIN;
        cin >> n >> k;
        vector<ll> v(n), pre(n + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            cnt += v[i];
            pre[i + 1] = cnt;
        }

        if (cnt <= k)
        {
            cout << 0 << endl;
            continue;
        }

        sort(v.begin(), v.end());
        MIN = v[0];

        ll l = 1, r = cnt - k + 1;
        ll m;
        ll ncnt = cnt, nmin = MIN;

        while(l != r-1)
        {
            m = (l+r) / 2;

            bool valid = false;
            for(int i = m-n-1; i < 2*m-n-1; i++)
            {
                nmin = MIN - i;
                ncnt = cnt - i;
                ncnt = ncnt - (pre[n] - pre[n-i]) + (n-i)*nmin;

                if(ncnt <= k)
                {
                    valid = true;
                    break;
                }
            }

            if(valid)
                r = m;
            else
                l = m;
        }
        cout << m << endl;

    }
    return 0;
}