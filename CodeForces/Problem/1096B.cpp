#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MOD 998244353
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll len, ans = 0;
    string str;

    cin >> len >> str;

    char lc, rc;
    ll lcnt = 1, rcnt = 1;
    lc = str[0], rc = str[len-1];

    for(int i = 1; i < len; i++)
    {
        if(lc == str[i])
            lcnt++ ;
        else
            break;
    }
    for(int i = len-2; i >= 0; i--)
    {
        if(rc == str[i])
            rcnt++;
        else
            break;
    }


    ans = (lcnt + rcnt) % MOD;
    if(lc == rc)
    {
        ans = (ans + lcnt * rcnt) % MOD;
    }
    cout << ans + 1;
    return 0;
}