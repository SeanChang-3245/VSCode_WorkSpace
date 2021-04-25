#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long sum = 0;

    for(int i = 3; i <= n; i++)
    {
        sum += i * (i-1);
    }
    cout << sum;
    return 0;

}