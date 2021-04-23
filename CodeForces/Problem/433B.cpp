#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int len;
    cin >> len;

    vector<int> vec(len+1);
    vector<ll> vpre(len+1,0);
    vector<ll> upre(len+1,0);

    for(int i = 1; i <= len; i++)
    {
        cin >> vec[i];
        if(i == 1)
            vpre[1] = vec[1];
        else
            vpre[i] = vec[i] + vpre[i-1]; 
    }

    auto it = vec.begin()++;
    sort(it, vec.end());
    for(int i = 1; i <= len; i++)
    {
        if(i == 1)
            upre[1] = vec[1];
        else
            upre[i] = vec[i] + upre[i-1];
    }

    int q;
    cin >> q;

    while(q--)
    {
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 1)
            cout << vpre[r] - vpre[l-1] << endl;
        else
            cout << upre[r] - upre[l-1] << endl;
    }



}