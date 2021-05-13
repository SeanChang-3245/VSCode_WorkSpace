#include <bits/stdc++.h>
using namespace std;


#define endl '\n'

bool cmp(pair<int, int> l, pair<int, int> r)
{
    return l.first > r.first;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m, x;
        cin >> n >> m >> x;

        vector<pair<int, int>> h(n);
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            h[i] = {tmp, i};
        }

        sort(h.begin(), h.end(), cmp);

        set<pair<int, int>> s;

        int i = 0;
        for(; i < m; i++)
        {
            s.insert({h[i].first, i+1});
            ans[h[i].second] = i+1;
        }

        for(; i < n; i++)
        {
            int idx = (*s.begin()).second;
            int tmp = (*s.begin()).first + h[i].first;
            ans[h[i].second] = idx;
            s.erase(s.begin());
            s.insert({tmp, idx});
        }

        if((*s.rbegin()).first - (*s.begin()).first > x)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for(int i : ans)
                cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}