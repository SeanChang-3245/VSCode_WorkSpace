#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int sou;
    int des;
    int wt;

    edge()
    {
        sou = des = wt = 0;
    }
    edge(int a, int b, int c)
    {
        sou = a;
        des = b;
        wt = c;
    }
};

int find(vector<int>& Union, int cur)
{
    while(Union[cur] >= 0)
    {
        cur = Union[cur];
    }
    return cur;
}


bool cmp(edge l, edge r)
{
    return l.wt < r.wt;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    vector<vector<int>> ans(v, vector<int>(v, -1));
    vector<edge> krus;
    vector<int> unionfind(v, -1);

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> adj[i][j];
            if(i < j && adj[i][j] != -1)
                krus.push_back(edge(i, j, adj[i][j]));
        }
    }

    sort(krus.begin(), krus.end(), cmp);

    int cnt = 0;
    int total = 0;
    for(int i = 0; i < krus.size(); i++)
    {
        if(find(unionfind, krus[i].sou) != find(unionfind, krus[i].des))
        {
            ans[krus[i].sou][krus[i].des] = krus[i].wt;
            ans[krus[i].des][krus[i].sou] = krus[i].wt;

            total += krus[i].wt;
            unionfind[find(unionfind, krus[i].des)] = krus[i].sou;
            cnt++;


            cout << krus[i].sou << ' ' << krus[i].des;
            cout << endl;
        }

        if(cnt == v-1)
            break;
    }

    cout << endl << endl;
/*
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
*/
    cout << endl << "total:" << total;
    cout << endl << "edge:" << cnt;
    return 0;
}