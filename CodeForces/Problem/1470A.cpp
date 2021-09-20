#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> k;
vector<int> g;


bool cmp(int lhs, int rhs)
{
    return g[lhs-1] > g[rhs-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--)
    {
        long long ans = 0;
        int n, m, cnt = 0;
        cin >> n >> m;

        k.resize(n), g.resize(m);

        for(int& i : k)
            cin >> i;
        for(int& i : g)
            cin >> i;


        sort(k.begin(), k.end(), cmp);

        for(int i = 0; i < n; i++)
        {
            if(g[cnt] >=  g[k[i]-1])
            {
                ans += g[k[i]-1];
            }
            else
            {
                ans += g[cnt++];
            }
        }
        cout << ans << endl;
    }
    return 0;
}