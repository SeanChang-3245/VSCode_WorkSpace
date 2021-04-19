#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> table(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
            
    }

    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(table[i][j] == 1)
            {
                table[i][j] = min(table[i-1][j], min(table[i][j-1], table[i-1][j-1]))+1;
                ans = max(ans, table[i][j]);
            }
            
        }
    }
    cout << ans;
    return 0;



}