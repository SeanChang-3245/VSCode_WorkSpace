#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

class BIT
{
private:
    vector<ll> arr;

    int lowbit(int i)
    {
        return i & (-i);
    }

public:
    BIT(vector<ll> &v)
    {
        int len = v.size();
        arr.resize(len + 1);

        for (int i = 0; i < len; i++)
            modify(i, v[i]);
    }

    void modify(int pos, int v)
    {
        pos++;
        int len = arr.size();
        while (pos < len)
            arr[pos] += v, pos += lowbit(pos);
    }

    ll sum(int l, int r)
    {
        ll sum = 0;
        r++;

        while (r > 0)
            sum += arr[r], r -= lowbit(r);

        while (l > 0)
            sum -= arr[l], l -= lowbit(l);
        return sum;
    }

    void display()
    {
        for (ll i : arr)
            cout << i << ' ';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> v(n);

    for (ll &i : v)
        cin >> i;

    BIT b(v);

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
            cout << b.sum(l, r) << ' ';
    }

    b.modify(2, 3);
    cout << endl;

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
            cout << b.sum(l, r) << ' ';
    }

    return 0;
}