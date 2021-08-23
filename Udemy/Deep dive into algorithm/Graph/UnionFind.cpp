#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& dsu, int v)
{
    while(dsu[v] >= 0)
        v = dsu[v];
    return v;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<unordered_set<int>> v(num);
    set<pair<int, int>> edges;
    vector<int> dsu(num, -1);

    for(int i = 0; i < num; i++)
    {
        int tmp, k;
        cin >> tmp;
        for(int j = 0; j < tmp; j++)
        {
            cin >> k;
            v[i].insert(k);
            
            edges.insert(pair<int, int>(min(i, k), max(i, k)));
        }
    }

    for(pair<int, int> e : edges)
    {
        if(find(dsu, e.first) == find(dsu, e.second))
        {
            cout << "there is a cycle";
            return 0;
        }

        int A = find(dsu, e.first);
        int B = find(dsu, e.second);

        dsu[A] += dsu[B];
        dsu[B] = A;
    }


    cout << "cycle is not exist";
    return 0;
}