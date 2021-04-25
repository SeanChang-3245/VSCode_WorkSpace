#include <bits/stdc++.h>


using namespace std;


#define MAX 2005
#define ll long long
#define endl '\n'

ll mem[MAX][MAX];
ll s[MAX];

ll dp(int l, int r)
{
    if(mem[l][r] != -1)
        return mem[l][r];
    if(l == r)
        return 0;

    return mem[l][r] = s[r] - s[l] + min(dp(l+1, r), dp(l, r-1));

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len;
    cin >> len;

    for(int i = 0; i < len; i++)
        cin >> s[i];


    sort(s, s+len);

    memset(mem, -1, sizeof(mem));
    cout << dp(0, len-1);

    return 0;
}
