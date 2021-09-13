#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

ostream& operator<<(ostream& os, vector<ll>& v)
{
    for(ll i : v)
        os << i << ' ';
    return os;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll m, l, r, ans = 0;
        cin >> m >> l >> r;
        vector<ll> v(m);

        for(ll& i : v)
            cin >> i;

        sort(v.begin(), v.end());
        //cerr << "v_" << v << endl;

        for(int i = 0; i < m; i++)
        {
            if(v[i] >= r)
                break;
            
            auto lb = lower_bound(v.begin() + i, v.end(), l-v[i]);
            auto rb = upper_bound(v.begin() + i, v.end(), r-v[i]);
            rb--;

            //cerr << i << endl;
            //cerr << "lb_" << lb - v.begin() << endl;
            //cerr << "rb_" << rb - v.begin() << endl;

            ans += rb - v.begin() - (lb - v.begin()) + 1;
            if(lb-v.begin() <= i && i <= rb-v.begin())
                ans--;

        }
        cout << ans << endl;
    }
    return 0;
}