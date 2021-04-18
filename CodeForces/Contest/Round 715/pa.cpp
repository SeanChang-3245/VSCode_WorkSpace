#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool cmp (int l, int r)
{
    if(l % 2 == 1)
        return l < r;
    return r < l;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    for(int x = 0; x < t; x++)
    {

        int m;
        cin >> m;
        vector<int> vec;


        int tmp;
        for(int i = 0; i < m; i++)
        {
            cin >> tmp;
            if(tmp % 2 == 0)
                cout << tmp << ' ';
            else
                vec.push_back(tmp);
        }



        for(int i : vec)
            cout << i << ' ';
        cout << endl;

    }
    return 0;

}
