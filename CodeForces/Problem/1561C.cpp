#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int atk;
        cin >> atk;

        int cave;
        cin >> cave;

        vector<vector<ll>> def(cave, vector<ll>(10e9+100));
        for(int i = 0; i < cave; i++)
        {
            ll tmp;
            cin >> tmp;
            for(int j = 0; j < tmp; j++)
                cin >> def[i][j];
        }
    }
}