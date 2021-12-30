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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);

        ll cnt = 0, MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            cnt += v[i];
        }

        sort(v.begin(), v.end());
        MIN = v[0];

        if (cnt <= k)
        {
            cout << 0 << endl;
            continue;
        }

        ll l = 1, r = cnt - k + 1;
        ll m;
        ll ncnt = cnt;
        ll nmin = MIN;
        while (l != r - 1)
        {
            m = (l + r) / 2;
            bool valid = false;

            for (int i = m-n; i <= m; i++)
            {
                ncnt = cnt - i;
                nmin = MIN - i;

                for (int j = n - 1; j > 0 && n - 1 - j <= m - i - 1; j--)
                {
                    ncnt -= v[j] - nmin;
                }

                if (ncnt <= k)
                {
                    valid = true;
                    break;
                }
            }

            if (valid)
                r = m;
            else
                l = m;
        }

        bool valid = false;
        for(int i = m-n; i <= m; i++)
        {
            ncnt = cnt - i;
            nmin = MIN - i;

            for (int j = n - 1; j > 0 && n - 1 - j <= m - i - 1; j--)
                ncnt -= v[j] - nmin;

            if (ncnt <= k)
                valid = true;
        }
        
        if (valid)
            cout << m << endl;
        else
            cout << m + 1 << endl;
    }

    return 0;
}