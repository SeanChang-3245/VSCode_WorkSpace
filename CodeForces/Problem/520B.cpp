#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    ll ans = 0;

    if (a >= b)
    {
        cout << a - b;
        return 0;
    }

    ll k = (ll)ceil(log2(double(b) / (double)(a)));
    cerr << "K_" << k << endl;
    ans += k;
    a *= (ll)pow(2, k);

    while (k >= 0)
    {
        ll tmp = (ll)((a - b) / (ll)pow(2, k));
        ans += tmp;

        a -= tmp * (ll)pow(2, k);
        k--;
    }

    ans += a - b;
    cout << ans;
    return 0;
}