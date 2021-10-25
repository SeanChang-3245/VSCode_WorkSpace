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
    while(t--)
    {
        ll n;
        cin >> n;

        if(n < 24)
        {
            cout << "NO" << endl;
            continue;
        }
            
        stack<ll> q;
        bool b = false;

        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                q.push(i);
                n /= i;
            }

            if(q.size() == 2)
            {
                b = 1;
                if(q.top() == n)
                {
                    cout << "NO" << endl;
                }
                else
                {
                    cout << "YES" << endl;
                    while(q.size())
                        cout << q.top() << ' ', q.pop();
                    cout << n << endl;
                }
                break;
            }
        }
        if(!b)
            cout << "NO\n";

    }
    return 0;

}