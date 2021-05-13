#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin >> m;
        bool valid = true;

        vector<string> v(m);

        for(int i = 0; i < m; i++) 
            cin >> v[i];

        for(int i = 0; i < m; i++)
        {
            if(!valid)
                break;
            for(int j = 0; j < m; j++)
            {
                if(v[i][j] == '0')
                    continue;
                
                if(i + 1 < m && j + 1 < m)
                {
                    if(v[i][j+1] == '0' && v[i+1][j] == '0')
                    {
                        valid = false;
                        break;
                    }
                }


            }

        }


        

        if(valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}