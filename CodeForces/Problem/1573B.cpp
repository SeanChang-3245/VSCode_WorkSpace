#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb(a) push_back(a)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int len;
        cin >> len;
        int ans = INT_MAX;

        vector<int> odd(len), even(len), pos(len, INT_MAX);

        for(int i = 0; i < len; i++)
        {
            cin >> odd[i];
        }

        int rb = 0;
        for(int i = 0; i < len; i++)
        {
            cin >> even[i];

           // if(rb == len - 1)
             //   continue;

            for(int j = even[i] / 2 -1; j >= rb; j--)
            {
                pos[j] = min(i, pos[j]);
            }
            rb = max(rb, even[i] / 2 - 1);
        }

        for(int i = 0; i < len; i++)
        {
            ans = min(ans, i + pos[odd[i]/2]);
        }
        cout << ans << endl;
        
    }
    return 0;
}