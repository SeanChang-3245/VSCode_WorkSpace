#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, len, k;
    ll ans = 0;
    cin >> n >> len >> k;

    vector<ll> v(n);
    for(ll& i : v)
        cin >> i;
    
    ans += n;

    vector<ll> tmp(n-1);
    for(int i = 1; i < n; i++)
    {
        tmp[i-1] = v[i] - v[i-1];
    }
    sort(tmp.begin(), tmp.end());

    int i = 0;
    while(n > k)
    {
        ans += tmp[i++] - 1;
        n--;
    }

    cout << ans;
    return 0;
}