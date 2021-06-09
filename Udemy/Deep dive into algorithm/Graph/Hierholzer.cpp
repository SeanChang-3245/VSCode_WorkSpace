#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    vector<unordered_set<int>> v(num);

    for(int i = 0; i < num; i++)
    {
        int tmp, k;
        cin >> tmp;
        for(int j = 0; j < tmp; j++)
        {
            cin >> k;
            v[i].insert(k);
        }
    }

    stack<int> current_path;
    stack<int> circuit;

    current_path.push(0);
    while(current_path.size())
    {
        int tail = current_path.top();

        if(v[tail].empty())
        {
            circuit.push(tail);
            current_path.pop();
            continue;
        }

        current_path.push(*v[tail].begin());
        v[tail].erase(v[tail].begin());
    }

    while(circuit.size())
    {
        cout << circuit.top() << ' ';
        circuit.pop();
    }
    return 0;


}