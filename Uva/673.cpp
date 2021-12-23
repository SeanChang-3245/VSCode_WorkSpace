#include <iostream>
#include <stack>
#include <bits/stdc++.h>

#define endl '\n'
#define ll long long

using namespace std;


bool match(char a, char b)
{
    if(a == '(' && b == ')')
        return true;
    else if(a == '[' && b == ']')
        return true;

    return false;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        string str;
        stack<char> stk;
        cin >> str;

        if(str.size() == 0)
        {
            cout << "Yes";
            continue;
        }

        for(char c : str)
        {
            if(stk.size())
            {
                if(match(stk.top(), c))
                    stk.pop();
                else
                    stk.push(c);
            }
            else
                stk.push(c);

        }

        if(stk.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    return 0;
}
