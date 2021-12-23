#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //n種物品 背包大小為m
    ll n, m;
    cin >> n >> m;
    vector<int> cnt(n), w(n), v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i] >> cnt[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i < n+1; i++)
    {
        for(int j = 0; j < m+1; j++)
        {
            if(i*j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if(j < w[i])
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            for(int k = 0; k < min(j/w[i-1], cnt[i-1]); k++)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - k*w[i-1]] + k * v[i-1]);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}