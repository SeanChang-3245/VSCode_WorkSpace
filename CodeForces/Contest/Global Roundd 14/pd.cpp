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
        int m, l, r;
        int cnt = 0;
        cin >> m >> l >> r;
        vector<int> v(m, 0);

        for(int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;

            if(i < l)
                v[tmp-1]++;
            else
                v[tmp-1]--;
        }

        sort(v.begin(), v.end());

        int j = m-1;
        for(int i = 0; i < m; i++)
        {
            if(v[i] >= 0 || v[j] <= 0)
                break;
            
            while(v[i] < 0 && v[j] > 0 && i < j)
            {
                int tmpj = v[j];
                int tmpi = v[i];

                v[i] += min(-tmpi, tmpj);
                v[j] -= min(-tmpi, tmpj);

                cnt += min(-tmpi, tmpj);
                --j;
            }
            
        }

        int k = 0;
        for(int i = 0; i < m; i++)
        {
            cnt += abs(v[i]/2);
            v[i] -= v[i]/2*2;
            k += v[i];
        }

        cnt += abs(k);

        cout << cnt << endl;
    }
    return 0;
}