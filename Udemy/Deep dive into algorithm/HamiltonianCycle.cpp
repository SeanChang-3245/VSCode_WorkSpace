#include <bits/stdc++.h>
using namespace std;

int m, start;
bool valid = false;
vector<vector<int>> graph;
vector<int> path;
vector<int> visit;

ostream& operator<<(ostream& os, vector<int>& v)
{
    for(int i : v)
        os << i << ' ';
    return os;
}


void sol(int cnt, int cur)
{
    path.push_back(cur);

    if(cnt == m)
    {
        if(graph[cur][start] == 1)
        {
            cout << path << start << endl;
        }
        else
        {
            cout << "invalid" << endl;
        }

    }

    visit[cur] = 1;
    
    for(int i = 0; i < m; i++)
    {
        if(i == cur)
            continue;

        if(visit[i] == -1 && graph[cur][i] == 1)
            sol(cnt+1, i);
    }
    visit[cur] = -1;

    path.erase(prev(path.end()));
}


int main()
{
    cin >> m;

    visit.resize(m);
    graph.resize(m);
    for(vector<int>& v : graph)
        v.resize(m);

    for(int i = 0; i < m; i++)
    {
        visit[i] = -1;
        for(int j = 0; j < m; j++)
            cin >> graph[i][j];
    }



    for(int i = 0; i < m; i++)
    {
        start = i;
        sol(1, i);
        if(valid)
            cout << "valid" << endl;
        else
            cout << "invalid" << endl;

    }



}