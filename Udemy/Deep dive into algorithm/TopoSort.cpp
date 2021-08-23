#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>());
    stack<int> sorted, visit;
    unordered_set<int> check;

    for (int i = 0; i < v; i++)
    {
        int tmp;
        cin >> tmp;
        while (tmp--)
        {
            int k;
            cin >> k;
            adj[i].push_back(k);
        }
    }


    while (sorted.size() != v)
    {
        if (visit.size() == 0)
        {
            for (int i = 0; i < v; i++)
            {
                if (check.find(i) == check.end())
                {
                    visit.push(i);
                    check.insert(i);
                    break;
                }
            }
        }

        int cur = visit.top();

        if (adj[cur].size() == 0)
        {
            sorted.push(cur);
            visit.pop();
        }
        else
        {
            bool no_out = true;
            for (int i = 0; i < adj[cur].size(); i++)
            {
                if (check.find(adj[cur][i]) == check.end())
                {
                    check.insert(adj[cur][i]);
                    visit.push(adj[cur][i]);
                    no_out = false;
                }
            }

            if (no_out)
            {
                sorted.push(cur);
                visit.pop();
            }
        }
    }

    while(sorted.size())
    {
        cout << sorted.top() << ' ';
        sorted.pop();
    }


    /*
    for (int i = 0; i < v; i++)
    {
        if (visit.size() == 0)
        {
            if (check.find(i) == check.end())
            {
                check.insert(i);
                visit.push(i);
            }
            else
                continue;
        }

        if (adj[i].size() == 0)
        {
            sorted.push(i);
            visit.pop();
        }
        else
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (check.find(j) == check.end())
                {
                    check.insert(j);
                    visit.push(j);
                }
            }
        }
    }*/
    return 0;
}