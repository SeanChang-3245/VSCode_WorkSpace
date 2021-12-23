#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    vector<vector<ll>> dp(2, vector<ll>(m));
    
    ll p = 0, n = 0;

    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        if(i == 0)
        {
            if(tmp > 0)
                dp[0][0] = 1;
            else 
                dp[1][0] = 1;
        }
        else
        {
            if(tmp > 0)
            {
                dp[0][i] = 1 + dp[0][i-1];
                dp[1][i] = dp [1][i-1];
            }
            else
            {
                dp[0][i] = dp[1][i-1];
                dp[1][i] = 1 + dp[0][i-1];
            }
        }
        p += dp[0][i];
        n += dp[1][i];        
    }

    cout << n << ' ' << p;
    return 0;
}