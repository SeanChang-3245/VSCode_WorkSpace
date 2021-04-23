#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--)
    {
        ll m;
        cin >> m;

        vector<ll> vec(m);
        for(ll& i : vec)
            cin >> i;

        sort(vec.begin(), vec.end(), greater<ll>());

        ll a = 0, b = 0;

        for(ll i = 0; i < m ;i++)
        {   
            if(i % 2 == 0)
            {
                if(vec[i] % 2 == 0)
                    a += vec[i];
            }
            else 
            {
                if(vec[i] % 2 == 1)
                    b += vec[i];
            }

        }

        if(a > b)
            cout << "Alice" << endl;
        else if(a == b)
            cout << "Tie" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;

    

}