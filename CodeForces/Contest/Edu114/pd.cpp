#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int, int>

ostream& operator<<(ostream& os, vector<int>& v)
{
    for(int i : v)
        os << i << ' ';
    return os;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int slot;
    cin >> slot;
    vector<int> cur(slot);
    set<pair<int, pair<int, int>>> s;

    for(int x = 0; x < slot; x++)
    {
        int m;
        cin >> m;
        cur[x] = m;
        vector<int> v(m);
        for(int& i : v)
            cin >> i;
        
        int tmp = 0;
        for(int i = m-1; i > 0; i--)
        {
            tmp += v[i];
            s.insert(pair<int, pair<int, int>>(tmp, {x, i}));
        }
    }

    vector<int> ori = cur;

    int ban;
    cin >> ban;

    set<vector<int>> b;

    for(int x = 0; x < ban; x++)
    {
        vector<int> tmp(slot);
        for(int i = 0; i < slot; i++)
            cin >> tmp[i];
        b.insert(tmp);
    }

    auto it = s.begin();
    while(1)
    {
        if(b.find(cur) == b.end())
        {
            cout << cur;
            break;
        }
        //cur = ori;
        cur[(*it).second.first] = (*it).second.second;
        it++;
    }
    return 0;
}