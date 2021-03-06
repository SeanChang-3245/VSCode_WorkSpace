#include <bits/stdc++.h>
using namespace std;

int v, m;
vector<int> color;
vector<vector<int>> graph;
int ans = INT_MAX;
bool valid = false;

vector<int> display;


void sol(int cur)
{
    if(cur == v)
    {
        for(int i = 0; i < v; i++)
        {
            ans = min(ans, color[i]);
        }

        if(ans != -1)
        {
            valid = true;
            for(int i = 0; i < v; i++)
            {
                display[i] = color[i];
            }        
            
        }
        if(ans != -1)
            for(int i : color) cout << i << ' ';

        cout << endl;

        return;
    }

    set<int> colortmp;

    for(int i = 0; i < v; i++)
    {
        if(graph[cur][i] == 1 && color[i] != -1)
        {
            colortmp.insert(color[i]);
        }
    }
    
    int cnt = 1;
    while(cnt <= m)
    {
        if(colortmp.find(cnt) == colortmp.end())
        {
            color[cur] = cnt;
            sol(cur+1);
            color[cur] = -1;
        }
        ++cnt;
    }
    return;
}


vector<int> visit;
bool bfs()
{
    visit.resize(m);
    queue<int> q;
    for(int& i : color)
        i = 1;
    for(int& i : visit)
        i = -1;
    
    int cur = 0;

    q.push(0);

    int mx = 1;
    while(q.size())
    {
        for(int i = 0; i < v; i++)
        {
            if(graph[q.front()][i] == 1)
            {
                if(i == q.front())
                    continue;
                else
                {
                    
                    if(visit[i] == -1)
                    {
                        visit[i] = 1;
                        q.push(i);
                    }

                    if(color[i] == color[q.front()])
                    {
                        color[i]++;      
                        mx = max(mx, color[i]);
                    }
                }    
            }
        }
        q.pop();
    }


    if(mx > m)  
        return false;

    return true;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> v >> m;
    color.resize(v);
    display.resize(v);

    for(int& i : color)
        i = -1;

    graph.resize(v);
    for(vector<int>& vec : graph)
        vec.resize(v);

    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin >> graph[i][j];   
        }
    }

    cout << endl;
    sol(0);

    if(valid)
        for(int i : display) cout << i << ' ';
    else
        cout << "impossible" << endl;

    cout << endl;
    if(bfs())
    {
        cout << "valid";
    }
    else
        cout << "impossible";

}