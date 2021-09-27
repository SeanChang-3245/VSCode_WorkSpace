#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll len;
    cin >> len;
    

    vector<ll> v(len);
    vector<ll> ori;
    for(int i = 0; i < len; i++)
    {
        cin >> v[i];
    }
    ori = v;
    sort(v.begin(), v.end());

    ll l = 0, r = 0;
    bool flipped = false;

    for(int i = 0; i < len; i++)
    {
        if(v[i] != ori[i])
        {
            if(flipped == true)
            {
                cout << "no";
                return 0;
            }

            flipped = true;
            l = i;
            r = i;

            while(i < len && v[i] != ori[i])
            {
                r = i;
                i++;
            }

            for(int i = l, j = r; i <= r && j >= l; i++, j--)
            {
                if(ori[j] != v[i])
                {
                    cout << "no";
                    return 0;
                }
            }

        }
    }
    cout << "yes" << endl << l+1 << ' ' << r+1;
    return 0;
}