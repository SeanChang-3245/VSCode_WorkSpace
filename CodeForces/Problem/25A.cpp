#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;

    int lasteven = 0, lastodd = 0;
    int evencnt = 0, oddcnt = 0;

    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;

        if (tmp & 1 == 1)
        {
            lastodd = i + 1;
            oddcnt++;
        }
        else
        {
            lasteven = i + 1;
            evencnt++;
        }
    }

    if(evencnt == 1)
    {
        cout << lasteven;
    }
    else
    {
        cout << lastodd;
    }
    return 0;
}