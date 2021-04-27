#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<long> dp(7, 3e6);

    for(int i = 0; i < m; i++)
    {
        long tmp;
        string str;
        cin >> tmp >> str;
        sort(str.begin(), str.end());

        if(str == "A")
            dp[0] = min(dp[0], tmp);
        else if(str == "B")
            dp[1] = min(dp[1], tmp);
        else if(str == "C")
            dp[2] = min(dp[2], tmp);
        else if(str == "AB")
            dp[3] = min(dp[3], tmp);
        else if(str == "AC")
            dp[4] = min(dp[4], tmp);
        else if(str == "BC")
            dp[5] = min(dp[5], tmp);
        else if(str == "ABC")
            dp[6] = min(dp[6], tmp);
    }

    long ans;
    ans = min(dp[0]+dp[1]+dp[2], dp[0]+dp[5]);
    ans = min(ans, dp[1]+dp[4]);
    ans = min(ans, dp[2]+dp[3]);
    ans = min(ans, dp[6]);
    ans = min(ans, dp[3]+dp[4]);
    ans = min(ans, dp[3]+dp[5]);
    ans = min(ans, dp[4]+dp[5]);

    if(ans > 3e5)
        cout << -1;
    else
        cout << ans;

    return 0;

}