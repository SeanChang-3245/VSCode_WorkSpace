#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void print(vector<vector<int>>& dp, vector<int>& w, vector<int>& val, int i, int j)
{
    if(i * j == 0)
    {
        for(int k : ans)
            cout << k << ' ';
        cout << endl;
        return;
    }

    if(dp[i][j] == dp[i-1][j])
    {
        print(dp, w, val, i-1, j);
    }

    if(j-w[i-1] >= 0 && dp[i][j] == dp[i-1][j-w[i-1]] + val[i-1])
    {
        ans.push_back(i-1);
        print(dp, w, val, i-1, j-w[i-1]);
        ans.erase(--ans.end());
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, cap;
    cin >> m >> cap;
    vector<int> val(m);
    vector<int> w(m);

    for(int i = 0; i < m; i++) cin >> val[i];
    for(int i = 0; i < m; i++) cin >> w[i];

    vector<vector<int>> dp(m+1, vector<int>(cap+1));

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= cap; j++)
        {
            if(i * j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if(w[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }
            
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + val[i-1]);
        }
    }

    cout << *(*dp.rbegin()).rbegin() << endl;
    print(dp, w, val, m, cap);
    return 0;
}