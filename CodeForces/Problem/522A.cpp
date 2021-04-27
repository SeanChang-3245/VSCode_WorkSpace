#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    map<string, int> mp;
    vector<int> un(m+5, -1);
    int ans = INT_MIN;

    for(int i = 0; i < m; i++)
    {
        string str1, str2;
        cin >> str1;

        for(char& c : str1)
            c = tolower(c);

        if(mp.find(str1) == mp.end())
        {
            mp.insert(pair<string, int>(str1, mp.size()));
        }
        cin >> str2 >> str2;

        for(char& c : str2)
            c = tolower(c);

        if(mp.find(str2) == mp.end())
        {
            mp.insert(pair<string, int>(str2, mp.size()));
        }

        un[mp[str1]] = mp[str2];

        int idx = mp[str1];
        int cnt = 1;
        while(un[idx] >= 0)
        {
            idx = un[idx];
            ++cnt;
        }

        un[idx] = min(un[idx], -cnt);
        ans = max(ans, -un[idx]);

    }
    cout << ans;
    return 0;

    
}