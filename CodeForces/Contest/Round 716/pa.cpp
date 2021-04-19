#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int x = 0; x < t; x++)
    {
        int m;
        cin >> m;

        int tmp;
        bool ans =false;
        for(int i = 0; i < m; i++)
        {
            cin >> tmp;

            if(ceil(sqrt(tmp)) != floor(sqrt(tmp)))
            {
                ans = true;
            }
        }

        if(ans)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
            


    }
    return 0 ;
}