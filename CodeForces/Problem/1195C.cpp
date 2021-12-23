#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<vector<ll>> v(2, vector<ll>(m));
    vector<vector<ll>> dp(3, vector<ll>(m));

    for(int i = 0; i < m; i++)
        cin >> v[0][i];
    for(int i = 0; i < m; i++)
        cin >> v[1][i];

    dp[0][0] = 0, dp[1][0] = v[0][0], dp[2][0] = v[1][0];

    for(int i = 1; i < m; i++)
    {
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + v[0][i];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + v[1][i];
    }

    cout << max(dp[0][m-1], max(dp[1][m-1], dp[2][m-1]));
    return 0;
}