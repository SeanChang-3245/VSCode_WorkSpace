#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<ll> w(n), v(n), c(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i] >> c[i];

    for (int i = 1; i < n + 1; i++)
    {
        for (int x = 0; x < w[i - 1]; x++)
        {
            deque<ll> mq;

            for (int k = x; k < m + 1; k += w[i - 1])
            {  
                while (mq.size())
                {
                    if (dp[i - 1][k] > dp[i - 1][mq.back()] + (k - mq.back()) / w[i - 1] * v[i - 1])
                        mq.pop_back();
                    else
                        break;
                }

                mq.push_back(k);

                if ((k - mq.front()) / w[i - 1] > c[i - 1])
                    mq.pop_front();

                dp[i][k] = dp[i - 1][mq.front()] + (k - mq.front()) / w[i - 1] * v[i - 1];
            }
        }
    }

    cout << dp[n][m];
    return 0;
}