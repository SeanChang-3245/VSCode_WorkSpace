#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<ll> dp(m+1);
    for(int i = 0; i < m; i++)
    {
        ll tmp; 
        cin >> tmp;
        dp[i+1] = tmp + dp[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << (dp[r] - dp[l-1]) / 10 << endl;
    }
    return 0;
}