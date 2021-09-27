#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb(a) push_back(a)

map<char, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;

    string str;
    int len;
    cin >> len >> str;


    vector<vector<int>> v(3, vector<int>(3));
    vector<int> colorcnt(3);

    for(int i = 0; i < len; i++)
    {
        v[mp[str[i]]][i%3]++;
        colorcnt[mp[str[i]]]++;
    }


}