#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

struct edge
{
    int a;
    int b;

    edge(int _a, int _b)
    {
        a = _a;
        b = _b;
    }
};

int find(vector<int>& u, int a)
{
    while(u[a] >= 0)
    {
        a = u[a];
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    vector<edge> edges;
    vector<int> unionfind(v, -1);

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> adj[i][j];

            if(i < j && adj[i][j] != 0)
            {
                edges.push_back(edge(i, j));
            }
        }
    }

    srand(time(NULL));
    int node = v;

    while(node != 2)
    {
        int rnd = rand() % edges.size();

        int root_a = find(unionfind, edges[rnd].a); // 尋找edges[rnd].a節點屬於哪個節點
        int root_b = find(unionfind, edges[rnd].b); // 尋找edges[rnd].b節點屬於哪個節點
        if(root_a != root_b) //若兩個節點不屬於同一個節點
        {
            node--;
            unionfind[root_b] = root_a; 
        }
    }

    int cnt = 0;

    for(int i = 0; i < edges.size(); i++)
    {
        // 因沒有從 edges 中刪除是自環的邊，因此要判斷每個邊的兩端是否連向同一個節點
        if(find(unionfind, edges[i].a) != find(unionfind, edges[i].b))
        {
            ++cnt;
        }
    }
    cout << cnt << endl;
    

    return 0;
}