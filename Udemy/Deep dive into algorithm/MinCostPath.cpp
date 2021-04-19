#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n, ans = 0;
    cin >> m >> n;

    vector<vector<int>> table(m, vector<int>(n));

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> table[i][j];
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
                continue;
            
            if(i == 0)
            {
                table[i][j] += table[i][j-1];
            }
            else if(j == 0)
            {
                table[i][j] += table[i-1][j];
            }
            else
            {
                table[i][j] += min(table[i-1][j], min(table[i][j-1], table[i-1][j-1]));
            }
        }
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            cout << table[i][j] << ' ';

        cout << endl;
    }

    cout << endl << endl;


    int i = m-1;
    int j = n-1;
    int prev = table[i][j];
    list<int> trace;

    while(i != 0 || j != 0)
    {
        if(i == 0)
        {
            while(j > 0)
            {
                trace.push_front(prev - table[0][j-1]);
                prev = table[0][j-1];
                --j;
            }
            break;
        }
        else if(j == 0)
        {
            while(i > 0)
            {
                trace.push_front(prev - table[i-1][0]);
                prev = table[i-1][0];
                --i;
            }
            break;
        }

        int MIN = min(table[i-1][j], min(table[i][j-1], table[i-1][j-1]));
        if(MIN == table[i-1][j])
        {
            trace.push_front(prev-table[i-1][j]);
            prev = table[i-1][j];
            --i;
        }
        else if(MIN == table[i][j-1])
        {
            trace.push_front(prev-table[i][j-1]);
            prev = table[i][j-1];
            --j;
        }
        else if(MIN == table[i-1][j-1])
        {
            trace.push_front(prev-table[i-1][j-1]);
            prev = table[i-1][j-1];
            --j;
            --i;
        }

    }
    trace.push_front(table[0][0]);

    for(int k : trace)
        cout << k << ' ';

    cout << endl;

    cout << table[m-1][n-1];
    return 0;
}