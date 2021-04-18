#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int bf(vector<int>& vec, int l, int r)
{
    int m = INT_MIN;
    for(int i = 0; i <= r; i++)
    {
        if(vec[i] > m)
            m = vec[i];
    }
    return m;
}


int bf_min(vector<int>& vec, int l, int r)
{
    int m = INT_MAX;
    for(int i = 0; i <= r; i++)
    {
        if(vec[i] < m)
            m = vec[i];
    }
    return m;
}


int dp_min(vector<int>& vec, int l, int r)
{
    int len = vec.size();

    vector<vector<int>> dp(len, vector<int>(len, 0));

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            if(i == j)
            {
                dp[i][j] = vec[i];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1], vec[j]);
            }
        }
    }
    return dp[l][r];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<int> vec(m);
    for(int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }


}