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
        ll a, b, cnt = 0, ans = LLONG_MAX;
        cin >> a >> b;
        int tmp=a;

        
        for(int i = 0; i <= 30; i++)
        {
            if(b + i == 1)
                continue;

            cnt = i;

            while(tmp != 0)
            {
                tmp /= (b+i);
                ++cnt; 
            }
            tmp = a;
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;

}