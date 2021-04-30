#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int dp[105][105];

int sol(int m, int n, int k)
{
    if(m == 1)
    {
        if(k - n +1 == 0)
            return 1;
        else
            return 0;
    }

    if(n == 1)
    {
        if(k - m + 1 == 0)
            return 1;
        else
            return 0;
    }

    if(dp[m][n-1] != -1 && dp[m-1][n] != -1)
    {
        return dp[m][n] = max(dp[m][n-1], dp[m-1][n]);
    }
    else
        return dp[m][n] = max(sol(m, n-1, k-m), sol(m-1, n, k-n));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        memset(dp, -1, sizeof(dp));

        int m, n, k;
        cin >> m >> n >> k;

        if(sol(m, n, k) == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
    
}