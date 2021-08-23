#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<unordered_set<int>> v(num);
    vector<int> used(num);
    vector<bool> in_deg(num);

    for (int i = 0; i < num; i++)
    {
        int tmp, k;
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            cin >> k;
            v[i].insert(k);
            in_deg[k] = true;
        }
    }

    stack<int> dfs;
    stack<int> path;

    for (int i = 0; i < num; i++)
    {
        if (!in_deg[i])
        {
            dfs.push(i);
        }
    }

    while (dfs.size())
    {
        int cur = dfs.top();
        bool end = true;
        used[cur] = true;

        for (int i : v[cur])
        {
            if (used[i] == false)
            {
                end = false;
                break;
            }
        }

        if (end == true)
        {
            path.push(cur);
            dfs.pop();
            continue;
        }

        for (int i : v[cur])
        {
            if (used[i] == false)
                dfs.push(i);
        }
    }

    while (path.size())
    {
        cout << path.top() << ' ';
        path.pop();
    }
    return 0;
}