#include <bits/stdc++.h>
using namespace std;

int m;
vector<vector<int>> board;
vector<vector<int>> ans;

void sol(int x, int y)
{
   // cout << x << ' ' << y << endl;

    ans[x][y] = 1;

    if(x == m-1 && y == m-1)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        return;
    }



    int nx = x + 1;
    int ny = y + 1;


    if(nx < m && board[nx][y] == 1)
    {
        sol(nx, y);
    }
    if (ny < m && board[x][ny] == 1)
    {
        sol(x, ny);
    }
    ans[x][y] = 0;
    return ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> m;

    board.resize(m);
    ans.resize(m);
    for(int i = 0; i < m; i++)
    {
        board[i].resize(m);
        ans[i].resize(m);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            ans[i][j] = 0;
        }
    }

    sol(0, 0);

    return 0;
}