#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


unsigned long long fr(int m)
{
    long long ans = 1;
    for(int i = 1; i <= m; i++)
        ans *= i;
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    string tar;
    cin >> str >> tar;

    int pos = 0;
    int tpos = 0;
    int q = 0;
    int m = str.size();

    for(int i = 0; i < m; i++)
    {
        if(tar[i] == '+')
            ++tpos;
        else if(tar[i] == '-')
            --tpos;
        else
            ++q;

        if(str[i] == '+')
            ++pos;
        else
            --pos;
    }

    double ans = 0;
    if(abs(tpos - pos) > q || abs(tpos-pos)%2 != q%2)
        ans = 0;
    else
    {
        int plus, minus;
        if(tpos >= pos)
        {
            plus = tpos - pos;
            minus = (q - plus) / 2;
            plus += minus;
        }
        else
        {
            minus = pos - tpos;
            plus = (q - minus) /2;
            minus += plus;
        }

        ans = fr(q) / fr(minus) / fr(plus) / pow(2, q);

    }
    
    cout << fixed << setprecision(12) << ans;
    return 0;

}