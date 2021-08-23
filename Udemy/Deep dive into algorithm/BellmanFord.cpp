#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int src;
    int des;
    int wt;

    edge(int a, int b, int c)
    {
        src = a;
        des = b;
        wt = c;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, sou;
    bool neg_cycle = false;
    cin >> v >> sou;

    vector<vector<int>> adj(v, vector<int>(v));
    vector<int> dist(v, INT_MAX); //將所有節點的距離設為 INT_MAX
    vector<edge> edges;

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
            if(adj[i][j] != INT_MIN)
                edges.push_back(edge(i, j, adj[i][j]));
        }
    }

    dist[sou] = 0; // 將根節點的距離設為0

    for(int t = 0; t < v-1; t++)
    {
       for(edge e : edges)
       {
           // e.src 表此邊的源點  e.des 表此邊的指向的節點
           if(dist[e.src] != INT_MAX && dist[e.des] > dist[e.src] + e.wt)
           {
               dist[e.des] = dist[e.src] + e.wt;
           }
       }
    }
    //檢查是否存在負環
    for(int i = 0; i < edges.size(); i++)
    {
        // 因若有負環 每個節點的最短距離應為無限小
        if(dist[edges[i].des] > dist[edges[i].src] + adj[edges[i].src][edges[i].des]) 
        {
            neg_cycle = true;
            break;
        }
    }

    if(neg_cycle)
    {
        cout << "neg_cycle";
        return 0;
    }

    for(int i = 0; i < v; i++)
    {
        cout << dist[i] << ' ';
    }
    return 0;


}