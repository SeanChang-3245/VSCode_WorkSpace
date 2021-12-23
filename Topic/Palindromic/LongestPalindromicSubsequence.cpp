#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    int len = str.size();

    vector<vector<int>> dp(len, vector<int>(len, 1));
    int ans = INT_MIN;

    for(int k = 1; k < len; k++)
    {
        for(int i = 0; k + i < len; i++)
        {
            int j = k + i;

            if(j - i == 1)
            {
                if(str[i] == str[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 1;
            }
            else
            {
                if(str[i] == str[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans;
    return 0;
}