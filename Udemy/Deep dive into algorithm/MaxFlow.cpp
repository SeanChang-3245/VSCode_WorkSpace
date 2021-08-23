#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, src, des, max_flow = 0;
    cin >> v >> src >> des;

    vector<vector<int>> cap(v, vector<int>(v, 0)); // 表示各邊的容量
    vector<bool> used(v, false);
    vector<int> parent(v);
    queue<int> bfs;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> cap[i][j];
        }
    }

    bool have_flow = false;

    do
    {
        // 初始化
        while(bfs.size())
            bfs.pop();
        for(int i = 0; i < v; i++)
        {
            parent[i] = 0;
            used[i] = false;
        }
        have_flow = false;
        int flow = INT_MAX;
        bfs.push(src);


        while (bfs.size())
        {
            int cur = bfs.front();
            bfs.pop();

            if (cur == des)
            {
                have_flow = true;
                int par;
                while (cur != src) // 尋找路徑上最小的容量
                {
                    par = parent[cur];
                    flow = min(flow, cap[par][cur]);
                    cur = par;
                }
                max_flow += flow;

                cur = des;
                while (cur != src)  // 加上反向且等容量的邊
                {
                    par = parent[cur];
                    cap[par][cur] -= flow;
                    cap[cur][par] += flow;
                    cur = par;
                }
                break;
            }

            for (int i = 0; i < v; i++)
            {
                if (cap[cur][i] != 0 && used[i] == false)
                {
                    used[i] = true;
                    parent[i] = cur;
                    bfs.push(i);
                }
            }
        }
    }while (have_flow);

    cout << max_flow;
    return 0;
}