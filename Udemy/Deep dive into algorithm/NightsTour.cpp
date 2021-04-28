#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int m;
const vector<pair<int, int>> moves{{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
vector<vector<int>> board;

void sol(int num, int x, int y)
{
    board[x][y] = num;

    if(num >= m*m - 1)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }

        cout << endl;
        cout << flush;
        return;
    }


    for(int i = 0; i < 8; i++)
    {
        int nx = x + moves[i].first;
        int ny = y + moves[i].second;
        if(nx < 0 || ny < 0 || nx >= m || ny >= m || num >= m*m || board[nx][ny] != -1)
        {
            continue;
        }
        sol(num+1, nx, ny);
    }

    board[x][y] = -1;
    
}


int main()
{
  //  ios_base::sync_with_stdio(false);
    //cin.tie(0);

    cin >> m;

    board.resize(m);
    for(int i = 0; i < m; i++)
    {
        board[i].resize(m);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
            board[i][j] = -1;
    }


    sol(0, 0, 0);

}