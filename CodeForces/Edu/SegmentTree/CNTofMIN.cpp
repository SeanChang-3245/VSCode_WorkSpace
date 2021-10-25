#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define pii(a, b) pair<int, int>(a, b)
#define PII pair<int, int>


struct segment
{
    vector<pair<int, int>> data;
    int size;

    void init(int n)
    {
        size = 1;
        while(size < n)
            size <<= 1;
        data.assign(2 * size, {INT_MAX, 0});
    }

    void set(int i, PII v)
    {
        set(i,  v, 0, 0, size);
        return;
    }
    void set(int i, PII v, int x, int lx, int lr)
    {
        if(lr - lx == 1)
        {
            data[x] = v;
            return;
        }

        int m = (lx + lr) / 2;
        if(i < m)
            set(i, v, x*2 + 1, lx, m);
        else
            set(i, v, x*2 + 2, m, lr);
        
        //
    }

    int cnt(int l, int r)
    {
        return cnt(l, r, 0, 0, size);
    }
    int cnt(int l, int r, int x, int lx, int lr)
    {

    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, ops;
    cin >> n >> ops;

    segment seg;
    seg.init(n);

    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        seg.set(i, pii(v, 1));
    }

    while(ops--)
    {
        int op;
        cin >> op;

        if(op == 1)
        {
            int i, v;
            cin >> i >> v;
            seg.set(i, pii(v, 1));
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << seg.cnt(l, r) << endl;
        }
    }

    return 0;
}