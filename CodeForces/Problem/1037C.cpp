#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len;
    string a, b;

    cin >> len;
    cin >> a >> b;


    stack<int> stk;
    int swap = 0;

    for(int i = 0; i < len; i++)
    {
        if(a[i] != b[i])
        {
            if(stk.size() && i - stk.top() <= 2 && b[stk.top()] != b[i])
            {
                swap += i - stk.top();
                stk.pop();
            }
            else
                stk.push(i);
        }
    }
    cout << swap + stk.size();
    return 0;

}