#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define pii(a, b) pair<ll, ll>(a, b)
#define PII pair<ll, ll>


ostream& operator<<(ostream& os, PII p)
{
    os << p.first << ' ' << p.second;
    return os;
}

struct segment
{
    vector<pair<ll, ll>> data;
    ll size;

    void init(ll n)
    {
        size = 1;
        while(size < n)
            size *= 2;
        data.assign(2 * size, {LLONG_MAX, 0});
    }

    void set(ll i, PII v)
    {
        set(i, v, 0, 0, size);
        return;
    }
    void set(ll i, PII v, ll x, ll lx, ll rx)
    {
        if(rx - lx == 1)
        {
            data[x] = v;
            return;
        }

        ll m = (lx + rx) / 2;
        if(i < m)
            set(i, v, x*2 + 1, lx, m);
        else
            set(i, v, x*2 + 2, m, rx);
        
        if(data[x*2 + 1].first == data[x*2 + 2].first)
            data[x].second = data[x*2 + 1].second + data[x*2 + 2].second;
        else if (data[x*2 + 1].first < data[x*2 + 2].first)
            data[x] = data[x*2 + 1];
        else
            data[x] = data[x*2 + 2];
        return;
    }

    PII cnt(ll l, ll r)
    {
        return cnt(l, r, 0, 0, size);
    }
    PII cnt(ll l, ll r, ll x, ll lx, ll rx)
    {
        if(l <= lx && rx <= r)
            return data[x];
        if(rx <= l || r <= lx)
            return pii(LLONG_MAX, 0);
        
        ll m = (lx + rx) / 2;

        PII s1=cnt(l, r, x*2 + 1, lx, m);
        PII s2=cnt(l, r, x*2 + 2, m, rx);
        
        if(s1.first == s2.first)
            return data[x] = pii(s1.first, s1.second + s2.second);
        else if(s1.first < s2.first)
            return data[x] = s1;
        else
            return data[x] = s2;
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, ops;
    cin >> n >> ops;

    segment seg;
    seg.init(n);

    for(ll i = 0; i < n; i++)
    {
        ll v;
        cin >> v;
        seg.set(i, pii(v, 1));
    }

    while(ops--)
    {
        ll op;
        cin >> op;

        if(op == 1)
        {
            ll i, v;
            cin >> i >> v;
            seg.set(i, pii(v, 1));
        }
        else if(op == 2)
        {
            ll l, r;
            cin >> l >> r;
            cout << seg.cnt(l, r) << endl;
        }
    }
    return 0;
}