#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int total = 0;

ostream& operator<<(ostream& os, vector<int>& v)
{
    for(int i : v)
        os << i << ' ';
    return os;
}

void sol(int n, int l, int r, string str, int cnt)
{
    if (total == n)
    {
        return;
    }

    if (cnt == 2*n)
    {
        cout << str << endl;
        total++;
        return;
    }

    if (l > r)
    {
        str += ')';
        sol(n, l, r + 1, str, cnt + 1);
        str.erase(str.end() - 1);
    }

    if (l < n)
    {
        str += '(';
        sol(n, l + 1, r, str, cnt + 1);
        str.erase(str.end() - 1);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string str;
        sol(n, 0, 0, str, 0);
        total = 0;
    }

    return 0;
}