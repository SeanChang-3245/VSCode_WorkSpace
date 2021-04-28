#include <bits/stdc++.h>
using namespace std;

int m;
vector<vector<int>> board;
set<int> pdia;
set<int> mdia;
set<int> ver;

void sol(int x, int y)
{
    board[x][y] = 1;

    if(y == m-1)
    {
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        board[x][y] = 0;
        return;
    }

    pdia.insert(x+y);
    mdia.insert(x-y);
    ver.insert(x);

    for(int i = 0; i < m; i++)
    {
        if(ver.find(i) == ver.end() && pdia.find(i+y+1) == pdia.end() && mdia.find(i-(y+1)) == mdia.end())
        {
            sol(i, y+1);
        }
    }

    board[x][y] = 0;
    ver.erase(x);
    pdia.erase(x+y);
    mdia.erase(x-y);
}

int main()
{
    cin >> m;

    board.resize(m);
    for(int i = 0; i < m; i++)
    {
        board[i].resize(m);
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            board[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++)
    {
        sol(i, 0);
    }
    return 0;


  
}
