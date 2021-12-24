#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<ll> v(n);
    deque<ll> dq;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        while (dq.size() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        while(dq.size() && i - dq.front() + 1 > k)
        {
            dq.pop_front();
        }

        if(i >= k-1)
            cout << v[dq.front()] << ' ';
    }
    return 0;
}
