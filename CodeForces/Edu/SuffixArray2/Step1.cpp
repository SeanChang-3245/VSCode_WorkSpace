#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    str += '$';
    int len = str.size();

    vector<int> p(len); //suffix array
    vector<int> ec(len);

    {
        vector<pair<char, int>> tmp(len);
        for(int i = 0; i < len; i++)
        {
            tmp[i] = {str[i], i};
        }

        sort(tmp.begin(), tmp.end());
        // tmp 為長度為 1 的 suffix array

        for(int i = 0; i < len; i++)
        {
            p[i] = tmp[i].second;
        }

        ec[p[0]] = 0;
        for(int i = 1; i < len; i++)
        {
            if(tmp[i].first == tmp[i-1].first)
                ec[p[i]] = ec[p[i-1]];
            else
                ec[p[i]] = ec[p[i-1]] + 1;
        }
    }


    int k = 0;
    while((1 << k) < len)
    {
        vector<pair<pair<int, int>, int>> tmp(len);

        for(int i = 0; i < len; i++)
        {
            tmp[i] = {{ec[i], ec[(i+ (1 << k)) % len]}, i};
        }

        sort(tmp.begin(), tmp.end());

        for(int i = 0; i < len; i++)
        {
            p[i] = tmp[i].second;
        }

        ec[p[0]] = 0;

        for(int i = 1; i < len; i++)
        {
            if(tmp[i].first == tmp[i-1].first)
                ec[p[i]] = ec[p[i-1]];
            else
                ec[p[i]] = ec[p[i-1]] + 1;
        }
        k++;
    }


    for(int i : p)
        cout << i << ' ';
    return 0;

}