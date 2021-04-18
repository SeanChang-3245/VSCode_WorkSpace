#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, tmp, ans = 0;
    cin  >> t;

    for(int x = 0; x < t; x++)
    {
        int m;
        cin >> m;

        vector<int> remain(3, 0);
        for(int i = 0; i < m ; i++)
        {
            cin >> tmp;
            remain[tmp%3]++;
        }
/*
        for(int i = 0; i < 3; i++)
            remain[i] = remain[i] - m/3;

        for(int i = 0; i < 2; i++)
        {
            ans += abs(remain[i]);
            remain[i+1]+=remain[i];
        }

        cout << ans << endl;
        ans = 0;
*/
        for(int i : remain)
            cout << i << ' ';
    }



}
