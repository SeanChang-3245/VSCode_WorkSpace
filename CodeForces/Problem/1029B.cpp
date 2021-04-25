#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    vector<long long> num(m);
    vector<long long> dp(m, 0);
    long long ans = 1;


    for(long long& i : num)
        cin >> i;
    
    dp[0] = 1;
    for(int i = 1; i < m; i++)
    {
        if(num[i] <= 2*num[i-1])
            dp[i] = dp[i-1]+1;
        else
            dp[i] = 1;

        ans = max(ans, dp[i]);

    }

    cout << ans;
}