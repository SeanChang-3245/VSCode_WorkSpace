#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, cnt = 0, herosum = 0;
    cin >> n;
    vector<ll> hero(n);
    for(ll& i : hero)
    {
        cin >> i;
        herosum += i;
    }
    
    ll m;
    cin >> m;

    vector<ll> atk(m), def(m);
    for(int i = 0; i < m; i++)
        cin >> def[i] >> atk[i];

    sort(hero.begin(), hero.end());

    for(int i = 0; i < m; i++)
    {
        auto lb = lower_bound(hero.begin(), hero.end(), def[i]);

        if(lb == hero.begin())
        {
            cnt += max((ll)0, atk[i] - (herosum - *lb));
        }
        else if (lb == hero.end())
        {
            lb = hero.end() - 1;
            cnt += def[i] - *lb + max(atk[i] - (herosum - *lb), (ll)0);
        } 
        else
        {
            auto prev = lb;
            prev--;

            ll tmp = 0;

            tmp = atk[i] - (herosum - *lb);
            tmp = min(max((ll)0, atk[i] - (herosum - *prev)) + max((ll)0, def[i]) - *prev, tmp);
            if(tmp > 0)
                cnt += tmp;
        }
        cout << cnt << endl;
        cnt = 0;
    }

    return 0;
}