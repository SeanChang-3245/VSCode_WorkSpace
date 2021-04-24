#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        ll m;
        cin >> m;

        if(m % 2050 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            string str;
            ll tmp = m / 2050;
            stringstream ss;
            ss << tmp;
            ss >> str;

            int cnt = 0;
            for(char c : str)
            {
                cnt += c-'0';
            }
            cout << cnt << endl;
        }
            
    }
    return 0;

}