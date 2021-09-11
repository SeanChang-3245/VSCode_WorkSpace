#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string rotate(string str, int a)
{
    string tmp = str;
    int len = str.size();
    
    for(int i = a; i < len; i++)
    {
        tmp[i-a] = str[i];
    }

    for(int i = 0; i < a; i++)
    {
        tmp[len - a + i] = str[i];
    }
    return tmp;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int m, n, a, b;
        cin >> m >> n >> a >> b;
        if(m*a != n*b)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

        int k = 0;
        string str;

        for(; k < a; k++)
            str += '1';
        for(; k < n; k++)
            str += '0';

        for(int i = 0; i < m; i++)
        {
            cout << str;
            str = rotate(str, a);
            cout << endl;
        }
    }
    return 0;
}