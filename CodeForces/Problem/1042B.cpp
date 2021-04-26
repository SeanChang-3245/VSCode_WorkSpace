#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<int> dp(7, INT_MAX);

    for(int i = 0; i < m; i++)
    {
        int tmp;
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

}