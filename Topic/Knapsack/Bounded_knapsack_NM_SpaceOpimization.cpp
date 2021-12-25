#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<ll> w(n), v(n), c(n);
    vector<ll> dp(m + 1);

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i] >> c[i];

    for (int i = 0; i < n; i++)
    {
        vector<ll> pre = dp;

        for (int x = 0; x < w[i]; x++)
        {
            deque<ll> mq;
            
            for(int k = x; k < m+1; k += w[i])
            {
                while(mq.size())
                {
                    if(pre[k] > pre[mq.back()] + (k-mq.back()) / w[i] * v[i])
                        mq.pop_back();
                    else
                        break;
                }

                mq.push_back(k);

                if((k-mq.front()) / w[i] > c[i])
                    mq.pop_front();
                
                dp[k] = pre[mq.front()] + (k-mq.front()) / w[i] * v[i];
            }
        }
    }

    cout << dp[m];
    return 0;
}