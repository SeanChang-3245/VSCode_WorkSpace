#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll a, b, m, k;
vector<int> num;
ll dp[12][12][2]; // [len][m cnt][f]

ll call(int len, int cnt, int f)
{
    if (cnt > k)
        return 0;

    if (len == num.size())
    {
        if (cnt == k)
            return 1;
        return 0;
    }

    if (dp[len][cnt][f] != -1)
        return dp[len][cnt][f];

    ll ans = 0;

    int limit = 9;
    if (f == true)
        limit = num[len];

    for (int i = 0; i <= limit; i++)
    {
        int ncnt = cnt, nf = f;
        if (i == m)
            ncnt++;
        if (nf == true && i < limit)
            nf = false;
        if(ncnt <= k) //剪枝
            ans += call(len + 1, ncnt, nf);
    }

    return dp[len][cnt][f] = ans;
}

ll solve(int b)
{
    num.clear();
    while (b > 0)
    {
        num.push_back(b % 10);
        b /= 10;
    }

    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof(dp));
    int ans = call(0, 0, 1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> m >> k;

    cout << solve(b) - solve(a - 1);

    return 0;
}