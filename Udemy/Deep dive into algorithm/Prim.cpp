#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    vector<vector<int>> ans(v, vector<int>(v, 0));


    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
        }
    }

    int cur = 0;
    int cnt = 0;
    int total = 0;
    vector<bool> used(v, false);
    set<pair<int, int>> edge;
    used[0] = true;

    while(cnt != v-1)
    {
        for(int i = 0; i < v; i++)
        {
            if(adj[cur][i] != -1)
            {
                if(used[i] == false)
                {
                    edge.insert(pair<int, int>(adj[cur][i], i));
                }
            }
        }

        auto it = edge.begin();
        while(used[(*it).second] == true)
            ++it;
        
        ans[cur][(*it).second] = (*it).first;
        ans[(*it).second][cur] = (*it).first;
        total += (*it).first;

        used[(*it).second] = true;
        cur = (*it).second;
        if(edge.size())
            edge.erase(it);
        
        cnt++;
    }

    cout << "total:" << total;

    cout << endl << endl;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;

}