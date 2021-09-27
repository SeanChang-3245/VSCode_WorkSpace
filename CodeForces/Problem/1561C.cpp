#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define pb(a) push_back(a)

bool cmp(pair<int, vector<int>>& l, pair<int, vector<int>>& r)
{
    return l.first < r.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int num;
        cin >> num;
        vector<pair<int, vector<int>>> cave(num);

        for(int i = 0; i < num; i++)
        {
            int tmp;
            cin >> tmp;

            for(int j = 0; j < tmp; j++)
            {
                int k;
                cin >> k;
                cave[i].second.pb(k);
                cave[i].first = max(cave[i].first, cave[i].second[j] - j);
            }
        }

        sort(cave.begin(), cave.end(), cmp);

        int ans = cave[0].first + 1;
        int sum = cave[0].second.size();

        for(int i = 1; i < num; i++)
        {
            ans = max(ans, cave[i].first - sum + 1);
            sum += cave[i].second.size();
        }
        cout << ans << endl;
    }
    return 0; 
}