#include <bits/stdc++.h>
using namespace std;

vector<int> un;

int find(int x)
{
    while(un[x] >= 0)
    {
        x = un[x];
    }
    return x;
}

void merge()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        vector<int> v(m);
        vector<int> mp(m);
        un.resize(m);
        for(int& i : un)
            i = -1;

        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
            mp[v[i]-1] = i;
        }
    }
}