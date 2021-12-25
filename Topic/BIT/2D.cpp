#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

int lowbit(int i)
{
    return i & (-i);
}

ll sum(vector<vector<ll>>& BIT, int x, int y)
{
    ll sum = 0;

    for(int i = x; i > 0; i -= lowbit(i))
    {
        for(int j = y; j > 0; j -= lowbit(j))
        {
            sum += BIT[i][j];
        }
    }
    return sum;
}

void modify(vector<vector<ll>>& BIT, int x, int y, int val)
{
    for(int i = x; i < BIT.size(); i += lowbit(i))
    {
        for(int j = y; j < BIT[i].size(); j += lowbit(j))
        {
            BIT[i][j] += val;
        }
    }
    return ;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<vector<ll>> bit(n+1, vector<ll>(m+1));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            modify(bit, i+1, j+1, grid[i][j]);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << sum(bit, i+1, j+1) << ' ';
        }
        cout << endl;
    }
    return 0;
}