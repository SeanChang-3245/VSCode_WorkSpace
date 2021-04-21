#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, q, k;
    cin >> len >> q >> k;

    vector<int> num(len+1, 0);
    vector<int> pre(len+1, 0);

    for(int i = 1; i <= len; i++)
    {
        cin >> num[i];
        if(i != 1)
        {
            pre[i] = pre[i-1] + num[i] - num[i-1] - 1;
        }
    }

    for(int i = 0; i < q; i++)
    {
        int l, r, ans = 0;
        cin >> l >> r;

        ans = num[l] - 1 + k - num[r] + 2*(pre[r] - pre[l]);
        cout << ans << endl;
    }
    return 0;

}