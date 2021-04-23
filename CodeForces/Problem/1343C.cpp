#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

bool sign(ll num)
{
    if(num > 0)
        return 1;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin >> m;
        ll sum = 0;
        
        ll tmp;
        ll maxx;
        ll prev;

        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(i == 0)
            {
                maxx = tmp;
                prev = tmp;
            }
            else
            {
                if(sign(prev) == sign(tmp))
                {
                    maxx = max(maxx, tmp);
                    prev = tmp;
                }
                else
                {
                    sum += maxx;
                    prev = tmp;
                    maxx = tmp;
                }
            }
        }
        sum += maxx;
        cout << sum << endl;


    }


}