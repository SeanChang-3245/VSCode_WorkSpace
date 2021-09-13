#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<int> ans;
vector<int> idx;
vector<int> v;

void sol(int l, int num, int r, int depth)
{
    if(l == r)
    {
        ans[idx[num]] = depth;
        return;
    }

    

        
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m;
        cin >> m;
        
        v.resize(m), idx.resize(m), ans.resize(m);

        for(int i = 0; i < m; i++)
        {
            cin >> v[i];
            idx[v[i]] = i;
        }

        sol(0, idx[m-1], m-1, 0);
        
    }
}