#include <bits/stdc++.h>
using namespace std;

int way[3];




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    cin >> way[0] >> way[1] >> way[2];

    vector<int> dp(m+1, 0);

    for(int i = 1; i <= m; i++)
    {
        if(i - way[0] >= 0)
            dp[i] = max(dp[i], dp[i-way[0]]+1);   
        if(i - way[1] >= 0)
            dp[i] = max(dp[i], dp[i-way[1]]+1);   
        if(i - way[2] >= 0)
            dp[i] = max(dp[i], dp[i-way[2]]+1);   

    }
    cout << *dp.rbegin();
    return 0;

}