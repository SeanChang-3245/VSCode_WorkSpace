#include <bits/stdc++.h>
using namespace std;

int a[105];
int b[105];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    int i = 0;
    int j = 0;

    int ans = 0;
    while(i < n && j < m)
    {
        if(abs(a[i] - b[j]) <= 1)
        {
            ++ans;
            ++i;
            ++j;
        }
        else if(a[i] > b[j])
            ++j;
        else
            ++i;
    }
    cout << ans;
    return 0;

}