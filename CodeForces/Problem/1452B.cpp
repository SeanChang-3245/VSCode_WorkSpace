#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int m;
        cin >> m;
        vector<ll> v(m);

        ll MIN = LLONG_MAX, MAX = LLONG_MIN;

        ll cnt = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> v[i];
            cnt += v[i];
            MIN = min(MIN, v[i]);
            MAX = max(MAX, v[i]);
        }

        MAX = max((cnt + m - 2) / (m-1), MAX);
        ll ans = MAX*(m-1) - cnt; 

        if(ans < 0)
            cout << ans + m - 1<< endl;
        else
            cout << ans << endl;

    }
    return 0;
}