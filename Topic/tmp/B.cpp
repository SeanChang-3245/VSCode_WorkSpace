#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll l, r;
        cin >> l >> r;

        bitset<21> b;

        int k = log2(r);

        ll h1 = 0, h2 = 0;
        for(int i = l; i <= r; i++)
        {
            b = i;

            h1 += b[k];
            h2 += b[k-1];
        }

        cout << min(r-l+1 - max(h1, h2), (r-l+1)/2) << endl;
    }
    return 0;
}