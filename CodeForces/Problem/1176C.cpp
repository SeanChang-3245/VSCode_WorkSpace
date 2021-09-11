#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> mp;
    mp[4] = 0, mp[8] = 1, mp[15] = 2, mp[16] = 3, mp[23] = 4, mp[42] = 5;


    int m;
    int cnt = 0;
    cin >> m;
    
    vector<int> v(m);
    vector<int> ans(m, -1);

    for(int &i : v)
        cin >> i;

    for(int i = 0; i < m; i++)
    {
        auto up = upper_bound(ans.begin(), ans.end(), mp[v[i]], greater<>());

        //cout << *up << endl;
        if(mp[v[i]] - *up == 1)
        {
            ans[up - ans.begin()]++;
            if(ans[up - ans.begin()] == 5)
                cnt++;
        }
    }

    cout << m - cnt*6;
    return 0;
}