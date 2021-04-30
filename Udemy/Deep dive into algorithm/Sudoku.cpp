#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(9, vector<int>(9));
bool valid = false;

bool check(int x, int y, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(i == y)
            continue;
        if(grid[x][i] == val)
            return false;
    }

    for(int i = 0; i < 9; i++)
    {
        if(i == x)
            continue;
        if(grid[i][y] == val)
            return false;
    }


    for(int i = x/3*3; i < x/3*3+3; i++)
    {
        for(int j = y/3*3; j < y/3*3+3; j++)
        {
            if(i == x && j == y)
                continue;
            
            if(grid[i][j] == val)
                return false;
        }
    }

    return true;
}

ostream& operator<<(ostream& os, vector<vector<int>>& grid)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            os << grid[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

void sol(int x, int y)
{
    if(grid[x][y] == 0)
    {
        for(int i = 1; i <= 9; i++)
        {
            if(check(x, y, i))
            {
                grid[x][y] = i;

                if(x == 8)
                {
                    if(y == 8)
                    {
                        valid = true;
                        cout << grid << endl << endl;
                        return;
                    }
                    else
                    {
                        sol(0, y+1);
                    }
                }
                else
                {
                    sol(x+1, y);
                }
                grid[x][y] = 0;
            }
        }
    }
    else
    {
        if(x == 8)
        {
            if(y == 8)
            {
                cout << grid << endl << endl;
                valid = true;
                return ;
            }
            else
            {
                sol(0, y+1);
            }
            
        }
        else
            sol(x+1, y);
    }

}


int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cin >> grid[i][j];
    }

    sol(0, 0);

    if(!valid)
        cout << "impossible";
    return 0;


}