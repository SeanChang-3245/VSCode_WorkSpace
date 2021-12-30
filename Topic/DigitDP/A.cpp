#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ll a, b, m, k;
vector<int> num;
ll dp[12][12][2];  // [len][m cnt][f]

ll sol(int len, int cnt, int f)
{
    if(cnt > k)
        return 0;

    if(dp[len][cnt][f] != -1)
        return dp[len][cnt][f];   

    if(len == num.size())
    {
        if(cnt == k)
            return 1;
        return 0;
    }

    ll ans = 0;

    int limit = 9;
    if(f == true)
        limit = num[len];
    
    for(int i = 0; i <= limit; i++)
    {
        int ncnt = cnt, nf;
        if(i == m)
            ncnt++;
        if(f == true && i < num[len])
            nf = false;
        ans += sol(len+1, ncnt, nf);
    }

    return dp[len][cnt][f] = ans;
}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> m >> k;

    int i = 0;
    while(b > 0)
    {
        num[i] = b%10;
        b /= 10;
        i++;
    }
    reverse(num.begin(), num.end());
    ll ansb = sol(0, 0, 1);

    memset(dp, -1, sizeof(dp));
    num.clear();
    i = 0;
    a--;
    while(a > 0)
    {
        num[i] = a%10;
        a /= 10;
        i++;
    }
    reverse(num.begin(), num.end());
    ll ansa = sol(0, 0, 1);

    cout << ansb - ansa << endl;
    return 0;
}