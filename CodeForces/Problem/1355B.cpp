#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m, cnt = 0;
        cin >> m;
        
        vector<int> vec(m);

        for(int& i : vec)
            cin >> i;
        
        sort(vec.begin(), vec.end());

        int l = 0, r = 0;

        while(r < m)
        {
            if(r-l+1 >= vec[r])
            {
                cnt++;
                l = r+1;
                r = l;
            }
            else
                ++r;
        }
        cout << cnt << endl;


    }
    return 0;
}   