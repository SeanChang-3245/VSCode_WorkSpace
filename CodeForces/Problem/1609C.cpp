#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<bool> prime(1000010, false);

bool isprime(int x)
{
    for(int i = 2; i*i <= x; i++)
    {
        if(x % i == 0)
            return prime[x] = false;
    }
    return prime[x] = true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    prime[2] = prime[3] = true;

    int t;
    cin >> t;

    while(t--)
    {
        int n, e;
        cin >> n >> e;
        vector<int> v(n);
        vector<int> dp(e, 1);
        vector<int> cnt(e, 0);
        vector<int> pos(e);

        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            int tmp;

            if(v[i] == 1)
                tmp = 1;
            else if (isprime(v[i]))
            {
                tmp = 2;
                pos[i%e] = i;
            }
            else
                tmp = 0;
            
            dp[i%e] *= tmp;

            if(dp[i%e] == 2)
            {
                cnt[i%e]++;
            }
        }

        ll ans = 0;
        for(int i = 0; i < e; i++)
        {
            int last = pos[i] / e * e;
        }
        cout << ans << endl;
    }
    return 0;
}