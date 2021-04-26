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

    for(int i = 0; i < m; i++)
    {
        string str1, str2;
        cin >> str1;
        if(mp.find(str1) == mp.end())
        {
            mp.insert(pair<string, int>(str1, mp.size()));
        }
        cin >> str2 >> str2;
        if(mp.find(str2) == mp.end())
        {
            mp.insert(pair<string, int>(str2, mp.size()));
        }

        

    }


    
}