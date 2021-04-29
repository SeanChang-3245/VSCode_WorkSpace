#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len, m;
    cin >> len >> m;

    vector<int> vec(len);
    multiset<int> cost;

    int ecnt = 0;
    int ocnt = 0;
    for(int i = 0; i < len ;i++)
    {
        cin >> vec[i];
    }

    for(int i = 0; i < len; i++)
    {
        if((vec[i]&1) == 0)
            ++ecnt;
        else
            ++ocnt;
        
        if(ecnt == ocnt && i+1 < len)
        {
            cost.insert(abs(vec[i]-vec[i+1]));
        }
    }

    if(ecnt != ocnt || cost.empty())
    {
        cout << 0;
        return 0;
    }
    
    int ans = 0;

    auto it = cost.begin();
    do
    {
        m -= *it;
        if(m >= 0)
        {
            ans++;
        }
        ++it;
    } while (m > 0 && it != cost.end());
    
    cout << ans;
    return 0;

}