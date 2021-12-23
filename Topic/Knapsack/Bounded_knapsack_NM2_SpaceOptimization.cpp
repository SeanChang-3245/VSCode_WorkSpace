#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> w(n), v(n), c(n);

    for(int i = 0; i < n; i++)
        cin >> w[i] >> v[i] >> c[i];

    vector<ll> dp(m+1, 0);

    for(int i = 0; i < n; i++)
    {
        for(int j = m; j >= w[i]; j--)
        {
            for(int k = 0; k <= c[i] && j-k*w[i] >= 0; k++)
            {
                dp[j] = max(dp[j], dp[j-k*w[i]] + k*v[i]);
            }
        }
    }

    cout << dp[m];
    return 0;
}