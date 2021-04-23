#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long len;
    long long m;
    bool table[26];
    memset(table, 0, sizeof(table));

    cin >> len >> m;

    string str;
    cin >> str;
    for(int i = 0; i < m; i++)
    {
        char c;
        cin >> c;
        table[c-'a'] = 1;
    }

    long long pre = 0, sum = 0;
    for(int i = 0; i < len; i++)
    {
        if(table[str[i]-'a'])
        {
            ++pre;
        }
        else
        {
            sum += pre * (pre+1) / 2;
            pre = 0;
        }
    }
    sum += pre * (pre+1)/2;

    cout << sum ;

}