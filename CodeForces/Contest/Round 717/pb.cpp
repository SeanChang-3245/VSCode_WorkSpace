#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t ;
    while(t--)
    {
        long long m;
        cin >> m;
        vector<long long> vec(m);
        vector<vector<bool>> table(m+1, vector<bool>(30, 0));

        for(int i = 0; i < m; i++)
        {
            int k = 0;
            cin >> vec[i];

            int tmp = vec[i];
            while(tmp > 0)
            {
                table[i][k] = 1 & tmp;
                tmp = tmp >> 1;
            }
        }

        

        for(int i = 0; i < m; i++)
        {
            for(int j = i; j - i + 1 <= m-1; j++)
            {

            }
        }
        
        
    }
    return 0;

}