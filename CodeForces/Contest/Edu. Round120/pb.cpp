#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 

vector<int> v;

bool cmp(int l, int r)
{
    return v[l] < v[r];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str;
        v.resize(n);

        vector<vector<ll>> dp(2, vector<ll>(n, LLONG_MAX));


        for(int i = 0; i < n; i++)
            cin >> v[i];
        
        cin >> str;


        for(int i = 0; i < n; i++)
        {
            if(str[i] == '0')
                dp[0].push_back(i);
            else   
                dp[1].push_back(i);
        }


        sort(dp[0].begin(), dp[0].end(), cmp);
        sort(dp[1].begin(), dp[1].end(), cmp);

/*
        for(int i : dp[0])
            cout << i << ' ';
        cout << endl;
        for(int i : dp[1])
            cout << i << ' ';
        cout << endl;
*/

        int k = 1;
        for(int i = 0; dp[0][i] != LLONG_MAX; i++)
        {
            v[dp[0][i]] = k++;
        }
        for(int i = 0; dp[1][i] != LLONG_MAX; i++)
        {
            v[dp[1][i]] = k++;
        }

        for(int i = 0; i < n; i++)
            cout << v[i] << ' ';

        cout << endl;
    }

    return 0;
}