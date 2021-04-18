#include <bits/stdc++.h>
using namespace std;

int query(vector<vector<int>>& sparse, int l, int r)
{
    int len = r - l +1;
    int k = log2(len);
    int remain = len - pow(2, k);

    return min(sparse[k][l], sparse[k][l+remain]);
}


int main()
{
    int len;
    cin >> len;
    vector<int> vec(len);

    for(int& i : vec)
        cin >> i;

    int wid = log2(len)+1;
    
    vector<vector<int>> sparse(wid, vector<int>(len));


    for(int i = 0; i < wid; i++)
    {
        for(int j = 0; j + pow(2, i)-1< len; j++)
        {
            if(i == 0)
            {
                sparse[i][j] = vec[j];
                continue;
            }

            sparse[i][j] = min(sparse[i-1][j], sparse[i-1][j + pow(2, i-1)]);
        }
    }

    

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            printf("[%d, %d] = %d", i, j, query(sparse, i, j));
            cout << endl;
        }
    }
}