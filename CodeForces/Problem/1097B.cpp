#include <bits/stdc++.h>
using namespace std;

bitset<15> bs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    vector<int> pos(m);
    
    int tmp;
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        pos[i] = tmp;
        sum += tmp;
    }

    int ans = sum;
    
    
    int k;
    for(int i = 0; i < (1<<m); i++)
    {
        k = i;
        int j = 0;
        while(k != 0)
        {
            if(k & 1 == 1)
            {
                ans -= 2*pos[j];
            }
            k >>= 1;
            ++j;
        }

        if(ans % 360 == 0)
        {
            cout << "YES";
            return 0;
        }
        ans = sum;
    }

    cout << "NO";
    return 0;

    
    


}