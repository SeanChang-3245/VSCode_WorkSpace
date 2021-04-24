#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int path[105][105];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        
        memset(path, -1, sizeof(path));
        
        vector<int> vec(n*m);

        for(int i = 0; i < n*m; i++)
            cin >> vec[i];

        sort(vec.begin(), vec.end());

        for(int i = 0; i < min(m, n); i++)
        {
            path[i][i] = vec[i];
        }

        if(n < m)
        {
            for(int i = n; i < m; i++)
            {
                path[i][n-1] = vec[i];
            }
        }
        else if(m < n)
        {
            for(int i = m; i < n; i++)
            {
                path[m-1][i] = vec[i];
            }
        }

        int k = max(m, n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(path[i][j] == -1)
                {
                    path[i][j] = vec[k];
                    ++k;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {   
                cout << path[j][i] << ' ';
            }
            cout << endl;
        }

    }

        
    return 0;

}