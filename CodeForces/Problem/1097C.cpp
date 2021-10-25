#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    priority_queue<int, vector<int>, greater<int>> l;
    priority_queue<int, vector<int>, greater<int>> r;
    int ans = 0;
    int correct = 0;

    while (m--)
    {
        string str;
        cin >> str;

        int len = str.size();
        int lb = 0, rb = 0;

        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(')
                lb++;
            else
            {
                if (lb != 0)
                    lb--;
                else
                    rb++;
            }
        }
        if (lb == 0 && rb == 0)
            correct++;
        else if (lb == 0 && rb != 0)
            r.push(rb);
        else if (lb != 0 && rb == 0)
            l.push(lb);
    }

    ans += correct / 2;

    while (l.size() && r.size())
    {
        if (l.top() == r.top())
        {
            ans++;
            l.pop(), r.pop();
        }
        else if (l.top() > r.top())
            r.pop();
        else
            l.pop();
    }
    cout << ans;
    return 0;
}