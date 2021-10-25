#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct segtree
{
    ll size;
    vector<ll> mins;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        mins.assign(2 * size, INT_MAX);
        return;
    }

    void set(int i, ll v)
    {
        set(i, v, 0, 0, size);
        return;
    }
    void set(int i, ll v, int x, int xl, int xr) // x 為在mins中的位置 xl為mins[x]在原始陣列中的左界
    {
        if (xr - xl == 1)
        {
            mins[x] = v;
            return;
        }

        ll m = (xr + xl) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, xl, m);
        else
            set(i, v, 2 * x + 2, m, xr);

        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        return;
    }

    ll findmin(int l, int r)
    {
        return findmin(l, r, 0, 0, size);
    }
    ll findmin(int l, int r, int x, int xl, int xr)
    {
        if (r <= xl || xr <= l)
            return INT_MAX;
        if (l <= xl && xr <= r)
            return mins[x];

        ll m = (xl + xr) / 2;

        ll s1 = findmin(l, r, 2 * x + 1, xl, m);
        ll s2 = findmin(l, r, 2 * x + 2, m, xr);
        return min(s1, s2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    segtree st;

    ll n, m;
    cin >> n >> m;

    st.init(n);
    for (int i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        st.set(i, v);
    }

    while (m--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int i;
            ll v;
            cin >> i >> v;
            st.set(i, v);
        }
        else if (op == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << st.findmin(l, r) << endl;
        }
    }
    return 0;
}