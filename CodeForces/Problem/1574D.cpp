#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb(a) push_back(a)

ll n;
unordered_set<string> ban;
string build;

void solve(ll pos)
{
    if(pos == n)
    {
        if(ban.find(build) == ban.end())
        {

        }
    }
}

ostream& operator<<(ostream& os, vector<ll>& v)
{
    for(ll i : v)
        os << i << ' ';
    return os;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vector<vector<ll>> v(n);
    build.resize(n);
    for(int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        v[i].resize(tmp);
        for(int j = 0; j < tmp; j++)
            cin >> v[i][j];
    }

    ll m;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        string tmp;
        for(int j = 0; j < n; j++)
        {
            stringstream ss;
            int num;
            cin >> num;
        
        }
    }  


}