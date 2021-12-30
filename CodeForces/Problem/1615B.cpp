#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define N 200000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<vector<int>> prefix(N+2, vector<int>(19));

    for(int i = 1; i <= N; i++)
    {
        int tmp = i;
        int j = 0;
        while(tmp > 0)
        {
            prefix[i][j] = (tmp & 1) + prefix[i-1][j];
            j++;
            tmp >>= 1;
        }
    }

    while(t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = 0;

        for(int i = 0; i < 19; i++)
        {
            ans = max(ans, prefix[r][i] - prefix[l-1][i]);
        }

        cout << r-l+1 - ans << endl;
    }
    return 0;
}