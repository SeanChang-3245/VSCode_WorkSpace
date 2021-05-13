#include <bits/stdc++.h>
using namespace std;


#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        double m;
        cin >> m;

        if(m == 1)
        {
            cout << "NO" << endl;
            continue;
        }

        if((long long)log2(m) == log2(m) || sqrt(m/2) == (long long)sqrt(m/2) || sqrt(m/4) == (long long)sqrt(m/4))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}