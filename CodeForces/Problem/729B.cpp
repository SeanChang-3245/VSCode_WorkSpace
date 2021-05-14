#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    long long cnt = 0;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    for (int i = 0; i < m; i++)
    {
        bool b = false;
        bool b1 = false;
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
                b = true;
            else if (!b)
                continue;
            else
                ++cnt;
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (v[i][j] == 1)
                b1 = true;
            else if (!b1)
                continue;
            else
                ++cnt;
        }
    }

    for (int i = 0; i < n; i++)
    {
        bool b = false;
        bool b1 = false;
        for (int j = 0; j < m; j++)
        {
            if(v[j][i] == 1)
                b = true;
            else if(!b)
                continue;
            else
                ++cnt;
        }

        for (int j = m-1; j >= 0; j--)
        {
            if(v[j][i] == 1)
                b1 = true;
            else if(!b1)
                continue;
            else
                ++cnt;
        }

    }
    cout << cnt;
    return 0;
}