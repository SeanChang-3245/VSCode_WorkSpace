#include <iostream>
#include <set>
#include <vector>

#define endl '\n'

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++)
    {
        int m,k;
        cin >> m >> k;

        if(k == 0)
        {
            for(int i = 1; i <= m; i++)
                cout << i << ' ';
            cout << endl;
            continue;
        }
        else if(m <= 2)
        {
            cout << -1 << endl;
            continue;
        }
        else if((m-1)/2 < k)
        {
            cout << -1 << endl;
            continue;
        }

        vector<int> vec(m);

        for(int i = 0; i < m; i++)
            vec[i] = i+1;

        for(int i = 1; i <= k; i++)
        {
            swap(vec[i*2-1], vec[i*2]);
        }

        for(int i : vec)
            cout << i << ' ';
        cout << endl;


    }
    return 0;

}
