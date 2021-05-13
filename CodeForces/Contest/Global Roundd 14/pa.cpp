#include <bits/stdc++.h>
using namespace std;

#define endl '\n'


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;
    while(t--)
    {
        int m, k;
        cin >> m >> k;
        set<int> s;
        vector<int> ans(m);
        int pos = 0;
        for(int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
        }

        auto it = s.begin();

        while(it != s.end())
        {
            if (k - *it != 0)
            {
                k -= *it;
                ans[pos++] = *it;
                s.erase(it);
                it = s.begin();
            }
            else
            {
                it++;
            }
        }

        if(s.empty())
        {
            cout << "YES" << endl;
            for(int i : ans)
                cout << i << ' ';
            cout << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}