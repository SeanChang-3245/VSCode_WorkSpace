#include <bits/stdc++.h>

using namespace std;

const long long MOD = 10e9 + 7;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        long long ans = 1;
        int n, k;
        cin >> n >> k;

        while(k--)
        {
            ans = (ans*n) % MOD;
        }
        cout << ans << endl;


    }
    return 0;

}