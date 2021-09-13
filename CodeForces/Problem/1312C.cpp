#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m, k;
        bool valid = true;
        cin >> m >> k;

        for(int i = 0; i < m; i++)
        {
            long long tmp;
            cin >> tmp;
            vector<int> bit(50);

            if(valid)
            {
                int cnt = 0;

                while(tmp != 0)
                {
                    bit[cnt] += tmp %= k;
                    tmp /= k;

                    if(bit[cnt++] >= 2)
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