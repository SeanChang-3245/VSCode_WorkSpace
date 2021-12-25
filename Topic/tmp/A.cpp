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
        int n;
        cin >> n;

        ll cnt = 0;
        for(int i = 0; i < n; i++)
        {
            ll tmp;
            cin >> tmp;
            cnt+=tmp;
        }

        if(cnt % n == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}