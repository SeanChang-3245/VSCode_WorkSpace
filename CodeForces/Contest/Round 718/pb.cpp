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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> path(n, vector<int>(m));
        vector<int> xmin(m); //橫

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                path[i][j] = -1;
        }


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int tmp;
                cin >> tmp;

                if(i == 0)
                {
                    path[0][j] = tmp;
                    xmin[j] = tmp;
                    continue;
                }

                int maxx = INT_MIN, maxidx;
                for(int k = 0; k < m; k++)
                {
                    if(xmin[k] - tmp > maxx && path[i][k] == -1)
                    {
                        maxx = xmin[k] - tmp;
                        maxidx = k;
                    }
                }

                path[i][maxidx] = tmp;
                xmin[maxidx] = min(xmin[maxidx], tmp); 
            }

            

           


        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << path[i][j] << ' ';
            }
            cout << endl;
        }
    }

        


}