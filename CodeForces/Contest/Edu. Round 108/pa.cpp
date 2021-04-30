#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll r, b, d;
        cin >> r >> b >> d;

        int mx = max(r,b);
        int mn = min(r,b);

        if(mx - mn*(1+d) <= 0)
            cout << "yes";
        else
            cout << "no";

        cout << endl;
    }
    return 0;

}