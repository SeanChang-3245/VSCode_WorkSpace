#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<ll> v(3);
    ll m;
    while (t--)
    {
        cin >> v[0] >> v[1] >> v[2] >> m;

        sort(v.begin(), v.end(), greater<>());

        if (m > v[0] + v[1] + v[2] - 3)
        {
            cout << "no" << endl;
            continue;
        }

        if(v[0] - v[1] - v[2] - 1 > m)
        {
            cout << "no" << endl;
            continue;
        }
        if(v[2] - v[1] - v[0] - 1 > m)
        {
            cout << "no" << endl;
            continue;
        }
        if(v[1] - v[0] - v[2] - 1 > m)
        {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }
    return 0;
}