#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> table(n, vector<int>(n, -1));

    for(int i = 0; i < n; i++)
    {
        cin >> table[i][i];
    }


    for(int i = n-1; i >= 0; i--)
    {
        int num = table[i][i];

        int x = i;
        int y = i;
        for(int j = 0; j < num-1; j++)
        {
            if(y+1 < n && table[y+1][x] == -1)
            {
                y++;
                table[y][x] = num;
            }
            else
            {
                x--;
                table[y][x] = num;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

}