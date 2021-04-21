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
        int m, k;
        cin >> m >> k;
        vector<int> vec(m);

        for(int& i : vec)
            cin >> i;

        int i = 0;
        while(k > 0 && i < m)
        {
            if(vec[i] > 0)
            {
                --vec[i];
                ++vec[m-1];
            }
            else
            {
                ++i;
                ++k;
            }

            --k;
        }
        
        for(int j : vec)
        {
            cout << j << ' ';
        }
        cout <<endl;

    }
    return 0;

}