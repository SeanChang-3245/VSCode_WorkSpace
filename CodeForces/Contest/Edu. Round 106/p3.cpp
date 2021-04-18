#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define endl '\n'
#define MP(a, b) pair<int, int>(a, b)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int n;
        cin >> n;

        vector<int> cost(n);
        vector<int> ans(n+1);
        map<int, int> mp; //(cost, cnt)

        for(int i : cost)
            cin >> i;

        ans[2] = 2 * cost[0] + 2 * cost[1];
        mp.insert(MP(cost[0], 2));
        mp.insert(MP(cost[1], 2));


        for(int i = 3; i <= n; i++)
        {
            auto it = mp.rbegin();
            while(cost[i] > it->first && it != mp.begin() && it->second > 1)
                it--;




        }




    }

    return 0;


}
