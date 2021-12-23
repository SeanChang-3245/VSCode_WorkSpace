#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<int> cnt(n), v(n), w(n);
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for(int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i] >> cnt[i];
    }

    

}