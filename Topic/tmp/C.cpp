#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string str1, str2;
        cin >> str1 >> str2;

        ll l1, l2, u1, u2, cnt;
        l1 = l2 = u1 = u2 = cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(str1[i] == '1')
                l1++;
            else
                u1++;
            
            if(str2[i] == '1')
                l2++;
            else
                u2++;

            if(str1[i] != str2[i])
                cnt++;
        }

        if(!((l1 == l2) || (l1-1 == u2)))
        {
            cout << -1 << endl;
            continue;
        }
        cout << cnt << endl;
    }
    return 0;
}