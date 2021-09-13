#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int len;
        string ori, ans, tmp;
        int rev = 1;

        cin >> len >> ori;
        ans = tmp = ori;

        for (int k = 2; k <= len; k++)
        {
            for (int i = 0; i + k - 1< len; i++)
            {
                reverse(tmp.begin() + i, tmp.begin() + i + k);
            }
            if (tmp < ans)
            {
                rev = k;
                ans = tmp;
            }
            tmp = ori;
        }
        cout << ans << endl;
        cout << rev << endl;
    }
    return 0;
}