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
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if(v[0] == v[1] && v[2] % 2 == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        if(v[1] == v[2] && v[0] % 2 == 0)
        {
            cout << "YES" << endl;
            continue;
        }

        if(v[0] + v[1] == v[2])
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}