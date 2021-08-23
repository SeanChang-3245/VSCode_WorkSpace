#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, sou;
    cin >> v >> sou;
    vector<vector<long>> adj(v, vector<long>(v));
    vector<long> parent(v);
    vector<bool> used(v, false);
    vector<long> dist(v, INT_MAX);

    dist[sou] = 0;
    parent[sou] = -1; //parent 紀錄在各節點在

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            cin >> adj[i][j];

    int cur = sou; //sou 為起始點
    int cnt = 0;
    while (cnt != v)
    {
        int tmp = INT_MAX;
        int k = cur;

        used[cur] = true;
        for (int i = 0; i < v; i++)
        {
            if (adj[cur][i] != -1) //存在cur-i的邊
            {
                if (dist[cur] + adj[cur][i] < dist[i])
                {
                    dist[i] = dist[cur] + adj[cur][i];
                    parent[i] = cur;
                }
            }
            // 尋找路徑最短且仍未確定的節點
            if (dist[i] < tmp && used[i] == false)
            {
                tmp = dist[i];
                k = i;
            }
        }

        cur = k;
        cnt++;
    }

    for (int i = 0; i < v; i++)
    {
        cout << dist[i] << ' ';
    }
    return 0;
}