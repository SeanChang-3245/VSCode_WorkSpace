#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

double fr(int k)
{
    double ans = 1;
    for(int i = 1; i <= k; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;
    int len = str1.size();

    int p = 0, m = 0;
    int q = 0;
    for(int i = 0; i < len; i++)
    {
        if(str1[i] == '+')
            ++p;
        else if(str1[i] == '-')
            ++m;

        if(str2[i] == '+')
            --p;
        else if(str2[i] == '-')
            --m;
        else
            ++q;
    }

    double ans;
    if(min(p, m) < 0)
    {
        ans = 0;
    }
    else
    {
        ans = 1/(fr(q)/fr(p)/fr(m));
    }

    cout << fixed << setprecision(12) << ans;
    return 0;

    
}