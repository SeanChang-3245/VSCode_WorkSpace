#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
bool a[105];
bool b[105];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;

    while(t--)
    {
        int m, ans = 0;
        cin >> m;

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        int tmp;
        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(a[tmp] == 0)
                a[tmp] = 1;
            else
                b[tmp] = 1;
        }

        int i = 0;
        while(a[i] == 1)
            ++i;
        ans += i;
        i = 0;
        while(b[i] == 1)
            ++i;
        ans+=i;
        cout << ans << endl;
    }
    return 0;

}