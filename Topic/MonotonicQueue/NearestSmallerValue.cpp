#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> v(n+1);
    deque<ll> dq;

    v[0] = LLONG_MIN;
    for(int i = 1; i < n+1; i++)
        cin >> v[i];

    dq.push_back(0);

    for(int i = 1; i < n+1; i++)
    {
        while(v[i] <= v[dq.back()])
            dq.pop_back();
        
        cout << dq.back() << ' ';
        dq.push_back(i);
    }
    return 0;
}