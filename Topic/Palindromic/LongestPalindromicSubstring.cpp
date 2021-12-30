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
    ll ans = 0;
    pair<ll, ll> p;
    ll len = str.size();

    vector<vector<bool>> dp(len, vector<bool>(len, true));

    for(int k = 1; k < len; k++)
    {
        for(int i = 0; i+k < len; i++)
        {
            int j = i + k;
            if(j-i == 1)
            {
                if(str[j] == str[i])
                {
                    if(2 > ans)
                    {
                        ans = 2;
                        p = pair<ll, ll>(i, j);
                    }
                    dp[i][j] = true;
                }
                else
                    dp[i][j] = false;
                continue;
            }
            
            if(dp[i+1][j-1] == true)
            {
                if(str[i] == str[j])
                {
                    dp[i][j] = true;
                    if(j-i+1 > ans)
                    {
                        ans = j-i+1;
                        p = pair<ll, ll>(i, j);
                    }
                }
                else
                    dp[i][j] = false;
            }
            else
                dp[i][j] = false;
        }
    }

    for(int i = p.first; i <= p.second; i++)
        cout << str[i];
    return 0;
}