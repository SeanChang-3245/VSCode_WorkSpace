#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    map<string, int> mp;

    while(t--)
    {
        string str;
        cin >> str;

        if(mp.find(str) == mp.end())
        {
            mp[str] = 0;
            cout << "OK" << endl;
        }
        else
        {
            mp[str]++;
            cout << str << mp[str] << endl;
        }
    }
    return 0;
}