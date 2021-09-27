#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define mp(a, b) pair<int, int>(a, b)

ostream& operator<<(ostream& os, vector<int>& v)
{
    for(int i : v)
        os << i << ' ';
    return os;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--)
    {
        int len;
        cin >> len;
        vector<int> v(len), pos(len);
        
        for(int i = 0; i < len; i++)
        {
            cin >> v[i];
            pos[v[i]-1] = i;
        }

        //cout << "V_" << v << endl;
        //cout << "POS_" << pos << endl;

        int r, l;
        l = r = pos[0];
        cout << 1;
        for(int i = 1; i < len; i++)
        {
            if(pos[i] < l)
                l = pos[i];
            else if(pos[i] > r)
                r = pos[i];

            if(r - l == i)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}